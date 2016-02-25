#include <rti/rti_word.h>

#include <vcl_iostream.h>
#include <vcl_vector.h>
#include <vcl_string.h>
#include <vcl_sstream.h>
#include <vul/vul_string.h>

#include <vul/vul_reg_exp.h>

rti_word::rti_word(const vcl_string& in_word, int in_freq, const vcl_string& in_arpabet, const vcl_string& in_morpheme, bool in_fun, float in_psa, float in_bipha)
  :spelling_(in_word), arpabet_(in_arpabet), morphemes_str_(in_morpheme), is_func_(in_fun), frequency_(in_freq), psa_(in_psa), bipha_(in_bipha), syllables_(0) 
{
  initialize();
}

void
rti_word::copy_arpabet_morpheme(rti_word_sptr old)
{
  reset_arpabet_morpheme();
  arpabet_ = old->arpabet();
  morphemes_str_ = old->morphemes();
  is_func_ = old->is_function();
  initialize();  
  //vcl_cout<<spelling_<<" , "<<old->spelling()<<" , "<< arpabet_ <<" , "<<arpabet_no_stresses_ <<vcl_endl;
}

void
rti_word::reset_arpabet_morpheme()
{
  arpabet_ = vcl_string("XXX");
  arpabet_no_stresses_ = vcl_string("");
  phonemes_.clear(); 
  stresses_.clear(); 
  morphemes_str_ = vcl_string("XXX");
  morphemes_.clear();
  syllables_ = 0;
  is_func_ = false;
  psa_ = 0;
  bipha_ = 0;
  neighbors_.clear();
}
void
rti_word::decompose(const vcl_string& in_str, vcl_vector<vcl_string>& components)
{
  vcl_stringstream str(in_str);
  while (!str.eof()) {
    vcl_string component;
	  str >> component;
    components.push_back(component);
  }
}

void 
rti_word::destress_arpabet(vcl_vector<vcl_string>& phonemes, vcl_vector<int>& stresses)
{  
  syllables_ = 0;
  vul_reg_exp re("([a-zA-Z]+[0-9])");
  stresses_.resize(phonemes.size(),-1);
  for (unsigned int i = 0; i<phonemes.size(); i++) 
    if (re.find(phonemes[i])) {
      int k = (phonemes[i][phonemes[i].length()-1]) - '0';
      stresses[i] = k; 
      phonemes[i].resize(phonemes[i].length()-1); //one element shorter
      if (k>=0) syllables_++; 
     } 
}

void 
rti_word::initialize() 
{
  decompose(arpabet_, phonemes_);
  destress_arpabet(phonemes_, stresses_); 
  for (unsigned int i=0; i<phonemes_.size()-1; i++)
    arpabet_no_stresses_ += phonemes_[i] + vcl_string(" ");
  arpabet_no_stresses_ += phonemes_[phonemes_.size()-1];
  decompose(morphemes_str_, morphemes_);
}

bool
rti_word::valid() const
{
    //return !(morphemes_str_ == vcl_string("XXX") || arpabet_ == vcl_string("XXX")); 
    return arpabet_ != vcl_string("XXX"); 
}

void
rti_word::set_morphemes(const vcl_string & in_morphemes)
{
    morphemes_str_ = in_morphemes;
    morphemes_.clear();
    decompose(in_morphemes, morphemes_);
}

XMLError
rti_word::read_xml_node(XMLElement* pRoot)
{
  spelling_ = pRoot->Attribute("spelling");

  //read in the attributes
  XMLError eResult = pRoot->QueryIntAttribute("frequency", &frequency_);
  XMLCheckResult(eResult);

  eResult = pRoot->QueryIntAttribute("syllables", &syllables_);
  XMLCheckResult(eResult);

  vcl_string str = pRoot->Attribute("function");
  if (vul_string_downcase(str) == vcl_string("yes")) is_func_ = true;
  else is_func_ = false;

  //read in other data stored as elements
  XMLElement * pElement = pRoot->FirstChildElement("Arpabet");
  if (pElement == nullptr) return XML_ERROR_PARSING_ELEMENT;
  arpabet_ = pElement->GetText();

  pElement = pRoot->FirstChildElement("Morphemes");
  if (pElement == nullptr) return XML_ERROR_PARSING_ELEMENT;
  morphemes_str_ = pElement->GetText();

  pElement = pRoot->FirstChildElement("PSegAve");
  if (pElement == nullptr) return XML_ERROR_PARSING_ELEMENT;
  eResult = pElement->QueryFloatText(&psa_);
  XMLCheckResult(eResult);

  pElement = pRoot->FirstChildElement("BiphAve");
  if (pElement == nullptr) return XML_ERROR_PARSING_ELEMENT;
  eResult = pElement->QueryFloatText(&bipha_);
  XMLCheckResult(eResult);

  pElement = pRoot->FirstChildElement("Neighborhood");
  if (pElement == nullptr) return XML_ERROR_PARSING_ELEMENT;

  unsigned int size;
  eResult = pElement->QueryUnsignedAttribute("size", &size);
  neighbors_.clear();
  neighbors_.reserve(size);
  XMLElement * pListElement = pElement->FirstChildElement("Neighbor");
  for (unsigned int i=0; i<size; i++) {
    neighbors_.push_back(pListElement->GetText());
    pListElement = pListElement->NextSiblingElement("Neighbor");
  }  

  initialize();

  return XML_SUCCESS;
}

void 
rti_word::write_xml_node(XMLDocument& xmlDoc, XMLElement* node)
{
  //store some data attributes

  if (is_func_) node->SetAttribute("function", "yes");
  else node->SetAttribute("function", "no");
  node->SetAttribute("frequency", frequency_);
  node->SetAttribute("syllables", syllables_);
  node->SetAttribute("spelling",spelling_.c_str());

  //store others as elements
  XMLElement* pElement = xmlDoc.NewElement("Arpabet");
  pElement->SetText(arpabet_.c_str());
  node->InsertEndChild(pElement);

  pElement = xmlDoc.NewElement("Morphemes");
  pElement->SetText(morphemes_str_.c_str());
  node->InsertEndChild(pElement);

  pElement = xmlDoc.NewElement("PSegAve");
  pElement->SetText(psa_);
  node->InsertEndChild(pElement);

  pElement = xmlDoc.NewElement("BiphAve");
  pElement->SetText(bipha_);
  node->InsertEndChild(pElement);

  pElement = xmlDoc.NewElement("Neighborhood");
  pElement->SetAttribute("size", unsigned(neighbors_.size()));
  for (unsigned int i=0; i<neighbors_.size(); i++) {
    XMLElement * pNbrElement = xmlDoc.NewElement("Neighbor");
	  pNbrElement->SetText(neighbors_[i].c_str());
	  pElement->InsertEndChild(pNbrElement);
  }
  node->InsertEndChild(pElement);
}
