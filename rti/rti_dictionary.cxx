#include <rti/rti_dictionary.h>

#include <vcl_iostream.h>
#include <vcl_vector.h>
#include <vcl_string.h>
#include <vnl/vnl_math.h>
#include <rti/rti_word_sptr.h>
#include <rti/rti_word.h>
#include <vul/vul_reg_exp.h>

#include <vcl_cassert.h>

rti_dictionary::rti_dictionary()
{
  is_valid_ = true;
  is_empty_ = true;
}

rti_dictionary::~rti_dictionary()
{}

bool
rti_dictionary::find(const vcl_string& word, int& idx)
{
  // if the dictictionary is empty, return right away
  if (words_.empty()) {
    idx = 0;
    return false;
  }

  //find position for the exact search using bisection search (iterative version) or return the position the word should be found.
  int imax = int(words_.size()-1);
  int imin = 0;
  while (imax >= imin) {
    idx = (imax+imin)/2; // calculate the midpoint for roughly equal partition
    if(words_[idx]->spelling() == word) {
      return true; // key found at index imid
    }
    else if (words_[idx]->spelling() < word)// determine which subarray to search
      imin = idx + 1; // change min index to search upper subarray
    else imax = idx - 1; // change max index to search lower subarray
  }

  if (words_[idx]->spelling() < word) idx++;
  return false;// key was not found
}

//find(.) should be called first to find out the pos for insertion. When a new word is inserted,
//up_to_date becomes invalid since psa, bipha and neighbors should be recomputed at certain point
void
rti_dictionary::insert(rti_word_sptr word, int pos) //successful insertion if entries are complete
{
  // if the new word should be at the end of list
  if (pos == words_.size()) words_.push_back(word);
  else { // if the new word should be inserted elsewhere
    words_.push_back(words_.back());
    for (int i = int(words_.size())-2; i > pos; i--)
    {
      words_[i] = words_[i-1]; //push the entry to the right
    }
    words_[pos] = word;
  }

  if (!word->valid()) is_valid_ = false;
  is_empty_ = false;
}

void
rti_dictionary::push_back(rti_word_sptr word)
{
  words_.push_back(word);
}

void
rti_dictionary::compute_PSegAves()
{
  assert(!is_empty_);
//Positional Segment Frequency (PSF): for each sound in the target word, sum together log10 values of frequencies (PSF)
//of words in the corpus having the same sound in the same position. Normalize the sum by dividing the total log10 frequency
//of all words in the corpus that have a segment in the given position.
//Positional segment average (PSA): average of PSF
  float psf = 0;
  float psa = 0;
  rti_word_sptr word;
  float count_nume;
  float count_deno;
  float ps_total;
  for (unsigned int i = 0; i<words_.size(); i++) {
    if (!words_[i]->valid()) continue;

    ps_total = 0;
    word = words_[i];
    vcl_vector<vcl_string> phonemes = word->phonemes();
    //vcl_cout<<"Target word = "<<word->spelling()<<vcl_endl;
    for (unsigned int j = 0; j<phonemes.size(); j++) {
      count_nume = 0;
      count_deno = 0;
      for (unsigned int k = 0; k<words_.size(); k++) {
        if (words_[k]->size() > j ) { //only consider words having sounds in the same position
          if ( words_[k]->phonemes()[j].compare(phonemes[j])== 0 ) {
            count_nume += log10((float)words_[k]->frequency())+1; //1 is added to the log value to avoid values of 0
          }
          count_deno += log10((float)words_[k]->frequency())+1;
          //vcl_cout<<"add to deno = "<<words_[k]->spelling()<<vcl_endl;
        }
      }
      ps_total += count_nume/count_deno;
    }
    word->set_psa(ps_total/phonemes.size());
  }
}

void
rti_dictionary::compute_BiphAves()
{
  assert(!is_empty_);
//Biphone frequency (BF): Similar to PSF, except that pairs of adjacent sounds are used instead of one single sound.
//Biphone average (BA): Average of BF and the denominator is the number of sounds minus 1.
  float bff = 0;
  float bfa = 0;
  rti_word_sptr word;
  float count_nume;
  float count_deno;
  float bf_total;
  for (unsigned int i = 0; i<words_.size(); i++) {
    if (words_[i]->size() == 1) {
      words_[i]->set_bipha(0.0);
      continue;
    }

    bf_total = 0;
    word = words_[i];
    vcl_vector<vcl_string> phonemes = word->phonemes();
    for (unsigned int j = 0; j<phonemes.size()-1; j++) {
      count_nume = 0;
      count_deno = 0;
      for (unsigned int k = 0; k<words_.size(); k++) {
        if (words_[k]->size() > j+1 ) { //only consider words having adjacent sounds in the same position
          if (words_[k]->phonemes()[j] == phonemes[j] && words_[k]->phonemes()[j+1] == phonemes[j+1])
            count_nume += log10((float)words_[k]->frequency()) + 1; //1 is added to the log value to avoid values of 0
          count_deno += log10((float)words_[k]->frequency()) + 1;
        }
      }
      bf_total += count_nume/count_deno;
    }
    word->set_bipha(bf_total/(phonemes.size()-1));
  }
}

void
rti_dictionary::compute_neighbors(rti_word_sptr target_word, int starting_index)
{
  assert(!is_empty_);

  //Neighborhood density: the number of words differing from a given target word by a one phoneme substitution, deletion, or addition.

  //one phoneme substitution
  //All candidates should have the same length as the target word
  vcl_vector<vcl_string> phonemes = target_word->phonemes();
  //vcl_cout<<"Target word = "<<target_word->spelling()<<vcl_endl;
  for (unsigned int j = 0; j<phonemes.size(); j++) {
    // produce the regular expression with the given phoneme replace with a .*
    vcl_string reg_exp_str = vcl_string("^");
    if (j == 0) reg_exp_str = reg_exp_str + vcl_string(".+");
    else reg_exp_str = reg_exp_str + phonemes[0];
    for (unsigned int k = 1; k<phonemes.size(); k++) {
      if (k==j) reg_exp_str = reg_exp_str + vcl_string(" .+") ;
      else reg_exp_str = reg_exp_str + vcl_string(" ") + phonemes[k];
    }
    reg_exp_str = reg_exp_str + vcl_string("$");
    //vcl_cout<<"sub exp = "<<reg_exp_str<<vcl_endl;

    vul_reg_exp re(reg_exp_str.c_str());
    // search the dictionary to find matching pattern
    for (unsigned int i = starting_index; i<words_.size(); i++) {
      if ( (words_[i]->size() != target_word->size()) || (!words_[i]->valid()) ) continue;

      if (re.find(words_[i]->arpabet_no_stresses().c_str()) && target_word->spelling().compare(words_[i]->spelling()) != 0) {
        //has to check if the neighbor already exisit, which happens for words with identical arpabet, e.g. bear and bear's
        bool nb_found = false;
        vcl_vector<vcl_string> neighbors = target_word->neighbors();
        for (unsigned int nb = 0; nb<neighbors.size(); nb++) {
          if ( neighbors[nb].compare(words_[i]->spelling())==0 ) {
            nb_found = true;
            break;
          }
        }
        if (!nb_found) {
          target_word->add_neighbor(words_[i]->spelling());
          words_[i]->add_neighbor(target_word->spelling());
          //vcl_cout<<"\t neighbor = "<<words_[i]->spelling()<<vcl_endl;
        }
      }
    }
  }

  //one phoneme deletion
  //All candidates should have one phoneme short of target word
  for (unsigned int j = 0; j<phonemes.size(); j++) {
    // produce the regular expression with the given phoneme replace with a .*
    vcl_string reg_exp_str = vcl_string("^");
    for (unsigned int k = 0; k<phonemes.size()-1; k++) {
      if (k!=j) reg_exp_str += phonemes[k] + vcl_string(" ");
    }
    if (j == phonemes.size()-1) reg_exp_str[reg_exp_str.length()-1] = '$';
    else reg_exp_str += phonemes[phonemes.size()-1]+vcl_string("$");
    //vcl_cout<<"del exp = "<<reg_exp_str<<vcl_endl;

    vul_reg_exp re(reg_exp_str.c_str());
    // search the dictionary to find matching pattern
    for (unsigned int i = starting_index; i<words_.size(); i++) {
      if ( (words_[i]->size() != target_word->size() -1) || (!words_[i]->valid()) ) continue;

      if (re.find(words_[i]->arpabet_no_stresses().c_str())) {
        target_word->add_neighbor(words_[i]->spelling());
        words_[i]->add_neighbor(target_word->spelling());
        //vcl_cout<<"\t neighbor = "<<words_[i]->spelling()<<vcl_endl;
      }
    }
  }

  //one phoneme addition (for each space between every two phonemes, and the space before and after the word, insert any phoneme (*) and check if such word exist
  //All candidates should be one phoneme more than the target word
  //Produce the reg_exp_str by inserting .+ inbetween any two phonemes and before and after the str.
  for (unsigned int space = 0; space<=phonemes.size(); space++) {
    // produce the regular expression with the given phoneme replace with a .+
    vcl_string reg_exp_str = vcl_string("^");
    if (space==0) reg_exp_str += vcl_string(".+ ") + phonemes[0] + vcl_string(" ");
    else reg_exp_str += phonemes[0] + vcl_string(" ");
    for (unsigned int k = 1; k<phonemes.size(); k++) {
      if (k == space) reg_exp_str += vcl_string(".+ ") + phonemes[k] + vcl_string(" ");
      else reg_exp_str += phonemes[k] + vcl_string(" ");
    }
    if (space < phonemes.size()) reg_exp_str[reg_exp_str.length()-1] = '$';
    if (space == phonemes.size()) reg_exp_str += vcl_string(".+$");
    //vcl_cout<<"addition exp = "<<reg_exp_str<<vcl_endl;

    vul_reg_exp re(reg_exp_str.c_str());
    // search the dictionary to find matching pattern
    for (unsigned int i = starting_index; i<words_.size(); i++) {
      if ( (words_[i]->size() != target_word->size() + 1) || (!words_[i]->valid()) ) continue;

      if (re.find(words_[i]->arpabet_no_stresses().c_str())) {
        target_word->add_neighbor(words_[i]->spelling());
        words_[i]->add_neighbor(target_word->spelling());
      }
    }
  }

}

void
rti_dictionary::compute_neighbors()
{
  //Neighborhood density: the number of words differing from a given target word by a one phoneme substitution, deletion, or addition.
  for (unsigned int i = 0; i<words_.size()-1; i++) {
    if (words_[i]->valid())
      compute_neighbors(words_[i], i+1);
  }
}


bool
rti_dictionary::import_dictionary(rti_dictionary *other_dictionary, bool *up_to_date)
{
    if (other_dictionary == NULL)
        return false;
    // If the old dictionary is provided, import information from the old dictionary
    //vcl_cout<<"Importing information from "<<old()<<" ..."<<vcl_endl;
    int pos;
    *up_to_date = true;
    printf("1\n");
    for (unsigned int i = 0; i<size(); i++) {
        if (other_dictionary->find((*this)[i]->spelling(), pos) && (*other_dictionary)[pos]->valid())
            (*this)[i]->copy_arpabet_morpheme( (*other_dictionary)[pos]);
        if (!(*this)[i]->valid()) {
            vcl_cout<<"\t"<<(*this)[i]->spelling()<<" not found"<<vcl_endl;
           *up_to_date = false;
        }
    }
    return true;
}

//New Code
void
<<<<<<< HEAD
rti_dictionary::get_words_added(std::vector<rti_word_sptr> listofWords)
=======
rti_dictionary::inc_wordfreq(vcl_string word, int pos)
>>>>>>> WordAnalysis/master
{
    int idx;
    for(int i; listofWords.size(); i++)
    {
        rti_word_sptr word = listofWords[i];
        if (!find(word->spelling(), idx))
            insert(word, idx);
    }
}

void
<<<<<<< HEAD
=======
rti_dictionary::get_wordsadded(vcl_string listofWords)
{   for(int i; listofWords.size(); i++){
    rti_word_sptr word = listofWords[i];
    insert(rti_word_sptr word, int idx);
}
    return 0;
}

void
>>>>>>> WordAnalysis/master
rti_dictionary::incomplete(rti_word_sptr word) //search each field
{
    if (word->arpabet() == "XXX" || word->morphemes() == "XXX")
        std::cout<< word;
}


rti_word_sptr
rti_dictionary::get(vcl_string spelling)
{
    for(int i = 0; i< words_.size(); i++)
    {
        if(words_.at(i)->spelling() == spelling)
        {
            return words_.at(i);
        }
    }
    return NULL;
}

std::vector<rti_word_sptr>
rti_dictionary::get_words()
{
    return words_;
}


void
rti_dictionary::display_message()
{
    std::cout<<"There are no differences between the lists";
}

<<<<<<< HEAD
XMLError
=======
void
>>>>>>> WordAnalysis/master
rti_dictionary::display_list(const vcl_string& filename)
{
    words_.clear();
    is_empty_ = true;
    is_valid_ = true;

	XMLDocument xmlDoc;

    //Parse the resource
    XMLError eResult = xmlDoc.LoadFile(filename.c_str() );
    XMLCheckResult(eResult);

    /*Get the root element node */
    XMLElement * pRoot = xmlDoc.RootElement();
    if (pRoot == nullptr) return XML_ERROR_FILE_READ_ERROR;

    //Read the words
    words_.reserve(10000);
    XMLElement* pElement = pRoot->FirstChildElement();
    while (pElement != nullptr) {
        rti_word_sptr word = new rti_word();
        word->read_xml_node(pElement);
        std::cout << word;
        if (!word->valid())
            is_valid_ = false;
    }
    if (!is_valid_)
        vcl_cout << filename << " has incomplete entries" << vcl_endl;

    is_empty_ = false;
    return XML_SUCCESS;
}
//New Code

XMLError
rti_dictionary::read_xml(const vcl_string& xml_filename)
{
  words_.clear();
  is_empty_ = true;
  is_valid_ = true;

	XMLDocument xmlDoc;

  //Parse the resource
  XMLError eResult = xmlDoc.LoadFile( xml_filename.c_str() );
  XMLCheckResult(eResult);

	/*Get the root element node */
  XMLElement * pRoot = xmlDoc.RootElement();
  if (pRoot == nullptr) return XML_ERROR_FILE_READ_ERROR;

  //Read the words
	words_.reserve(10000);
  XMLElement* pElement = pRoot->FirstChildElement();
  while (pElement != nullptr) {
    rti_word_sptr word = new rti_word();
    word->read_xml_node(pElement);
    if (!word->valid()) {
      is_valid_ = false;

    }
    words_.push_back(word);
    pElement = pElement->NextSiblingElement();
  }
  if (!is_valid_)
     vcl_cout<<xml_filename<<" has incomplete entries"<<vcl_endl;

  is_empty_ = false;
  return XML_SUCCESS;
}

XMLError
rti_dictionary::write_xml(vcl_string xml_filename, bool up_to_date)
{
  XMLDocument xmlDoc;
  XMLElement* root_node = xmlDoc.NewElement( "Dictionary" );
  if (is_valid_) root_node->SetAttribute("valid", "yes");
  else root_node->SetAttribute("valid", "no");
  xmlDoc.InsertFirstChild( root_node );
  root_node->SetAttribute("size",(int)words_.size());

  // write out the words in the dictionary
  for (unsigned int i = 0; i<words_.size(); i++) {
    XMLElement * wElement = xmlDoc.NewElement("W");
    words_[i]->write_xml_node(xmlDoc, wElement);
    root_node->InsertEndChild(wElement);
  }

  XMLError eResult = xmlDoc.SaveFile( xml_filename.c_str() );
  XMLCheckResult(eResult);
  return eResult;
}
