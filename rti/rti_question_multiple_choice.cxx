#include <vcl_iostream.h>
#include <vcl_cassert.h>
#include <vcl_sstream.h>
#include <vul/vul_string.h>
#include <rti/rti_question_multiple_choice.h>


rti_question_multiple_choice::rti_question_multiple_choice(Q_TYPE in_type, const vcl_string& in_question, int in_std, char in_answer, const vcl_string& in_evidence, const vcl_string& in_keywords, const vcl_string& in_indicator)
  : rti_question(in_type, in_question, in_std, 1, in_evidence, in_keywords, in_indicator)
{
  answer_ = toupper(in_answer);
  //vul_string_upcase(answer_);
}

void 
rti_question_multiple_choice::add_choice(char choice, const vcl_string& text)
{
  choices_.push_back(vcl_pair<char,vcl_string>(toupper(choice), text));
} 

bool 
rti_question_multiple_choice::correct_answer(char choice) const
{
  //vul_string_upcase(choice);
  choice = toupper(choice);
  return choice == answer_;
}

bool
rti_question_multiple_choice::get_choice(char choice, vcl_string& text) const
{
  assert(choices_.size());
  choice = toupper(choice); // make sure the choice is in upper case
  for (unsigned int i = 0; i<choices_.size(); i++) {
    if (choice == choices_[i].first) {
      text = choices_[i].second;
      return true;
    }
  }
  return false;
}

XMLError 
rti_question_multiple_choice::read_xml_node(XMLElement* node)
{
  rti_question::read_xml_node(node);  
  answer_ = node->Attribute("answer")[0];

  //read the choices
  XMLElement * pElement = node->FirstChildElement("Choices");
  XMLElement * pListElement = pElement->FirstChildElement();
  choices_.reserve(4);
  for (unsigned int i = 0; i< 4; i++) {
    char choice = pListElement->Name()[0];
    vcl_string text = pListElement->GetText();
    choices_.push_back(vcl_pair<char, vcl_string>(choice, text));
    pListElement = pListElement->NextSiblingElement();
  }

  return XML_SUCCESS;
}

void 
rti_question_multiple_choice::write_xml_node(XMLDocument& xmlDoc, XMLElement* node, int index)
{
  rti_question::write_xml_node(xmlDoc, node, index);

  vcl_stringstream ss;
  vcl_string answer;  
  ss << answer_;
  ss >> answer;
  node->SetAttribute("answer", answer.c_str());
  
  //write the choices
  XMLElement * pElement = xmlDoc.NewElement("Choices");
  for (unsigned int i = 0; i<choices_.size(); i++) {
    vcl_stringstream cc;
    vcl_string choice;  
    cc << choices_[i].first;
    cc >> choice;
    XMLElement * pListElement = xmlDoc.NewElement(choice.c_str());
    pListElement->SetText(choices_[i].second.c_str());
    pElement->InsertEndChild(pListElement);
  }
  node->InsertEndChild(pElement);
  
}

