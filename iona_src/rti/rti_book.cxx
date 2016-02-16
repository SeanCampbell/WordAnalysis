#include <rti/rti_book.h>

#include <vcl_iostream.h>
#include <vcl_vector.h>
#include <vcl_string.h>
#include <vcl_sstream.h>
#include <vcl_algorithm.h>

#include <vul/vul_string.h>
#include <vul/vul_reg_exp.h>

#include <fstream>

rti_book::rti_book(const vcl_string& in_title, const vcl_string& in_author, AGE in_age_range, const vcl_string& text_file)
  : title_(in_title), author_(in_author), age_range_(in_age_range) 
{
  vcl_vector< vcl_string > in_words;
  in_words.reserve(4000);
  //vul_reg_exp re("([a-zA-Z'_\\-]+)");
  vul_reg_exp re("([a-zA-Z']+)"); //eliminate compund words with - or _

  //strip out only words, convert to low cases, and sort
  //vcl_ifstream in_file(text_file);
  std::ifstream in_file(text_file);
  vcl_string word;
  //vcl_ofstream out_file("output.txt");
  std::ofstream out_file("output.txt");
  in_file>>word;
  while (!in_file.eof()) {
	  while (re.find(word)) {
      out_file<<re.match(1)<<" ";
          //in_words.push_back(vul_string_downcase(re.match(1)));
      const vcl_string &constmatch = re.match(1);
      vcl_string match = constmatch;
      in_words.push_back(vul_string_downcase(match));
      word = word.substr(re.end());
    }
    in_file>>word;
  }
  out_file.close();
  vcl_sort(in_words.begin(),in_words.end());
  word_count_ = (int)in_words.size();

  //Now do the count and output the result to the output file
  word = in_words[0];
  int count = 1;
  for (int i = 1; i<in_words.size(); i++) {
	  if (word == in_words[i]) count ++;
	  else {
      words_.push_back(vcl_pair<vcl_string,int>(word,count));
		  word = in_words[i];
		  count = 1;
	  }
  }
  words_.push_back(vcl_pair<vcl_string,int>(word,count));
  is_valid_ = true;
}

vcl_string
rti_book::title_downcase() const
{
  vcl_string out_title = title_;
  return vul_string_downcase(out_title);
}


XMLError 
rti_book::read_xml_node(XMLElement* pRoot)
{
  //read in the attributes
  title_ = pRoot->Attribute("title");
  author_ = pRoot->Attribute("author");

  vcl_string str = pRoot->Attribute("age");
  if (str == vcl_string("NS")) age_range_ = NS;
  else if (str == vcl_string("PK")) age_range_ = PK;
  else if (str == vcl_string("K")) age_range_ = K;
  else if (str == vcl_string("G1")) age_range_ = G1;
  else if (str == vcl_string("G2")) age_range_ = G2;
  else if (str == vcl_string("G3")) age_range_ = G3;
  else age_range_ = G4;

  //read in other data stored as elements
  XMLElement *pElement = pRoot->FirstChildElement("Words");
  if (pElement == nullptr) return XML_ERROR_PARSING_ELEMENT;

  XMLError eResult = pElement->QueryIntAttribute("total_count", &word_count_);
  XMLCheckResult(eResult);
  unsigned int size;
  eResult = pElement->QueryUnsignedAttribute("unique_words", &size);
  words_.clear();
  words_.reserve(size);
  XMLElement * pListElement = pElement->FirstChildElement("W");
  while (pListElement != nullptr) {
    vcl_pair<vcl_string,int> word(pListElement->GetText(),0);
    XMLError eResult = pListElement->QueryIntAttribute("freq",&word.second);
    XMLCheckResult(eResult);
    words_.push_back(word);
    pListElement = pListElement->NextSiblingElement("W");
  }

  is_valid_ = true;

  return XML_SUCCESS;
}
  
void 
rti_book::write_xml_node(XMLDocument& xmlDoc, XMLElement* node)
{
  //store some data attributes

  switch (age_range_) {
    case NS:  node->SetAttribute("age","NS"); break;
    case PK : node->SetAttribute("age","PK"); break;
    case K : node->SetAttribute("age","K"); break;
    case G1 : node->SetAttribute("age","G1"); break;
    case G2 : node->SetAttribute("age","G2"); break;
    case G3 : node->SetAttribute("age","G3"); break;
    case G4 : node->SetAttribute("age","G4"); break;
  }
  node->SetAttribute("author",author_.c_str());
  node->SetAttribute("title",title_.c_str());

  //store others as elements
  XMLElement * pElement = xmlDoc.NewElement("Words");
  pElement->SetAttribute("unique_words", unsigned(words_.size()));
  pElement->SetAttribute("total_count", word_count_);
  for (unsigned int i=0; i<words_.size(); i++) {
    vcl_string name = words_[i].first;
    XMLElement * wElement = xmlDoc.NewElement("W");
    wElement->SetAttribute("freq",words_[i].second);
    wElement->SetText(words_[i].first.c_str());
	  pElement->InsertEndChild(wElement);
  }
 
  node->InsertEndChild(pElement);
}
