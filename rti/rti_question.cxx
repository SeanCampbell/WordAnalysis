#include <vcl_iostream.h>
#include <rti/rti_question.h>

XMLError 
rti_question::read_xml_node(XMLElement* node)
{
  //read in the attributes
  XMLError eResult = node->QueryIntAttribute("std", &std_);
  XMLCheckResult(eResult);
  eResult = node->QueryIntAttribute("points", &points_);
  XMLCheckResult(eResult);

  vcl_string str = node->Attribute("type");
  if (str == vcl_string("R")) type_ = R;
  else if (str == vcl_string("LW")) type_ = LW;
  else type_ = RW;

  //read in other data stored as elements
  XMLElement * pElement = node->FirstChildElement("Text");
  if (pElement == nullptr) return XML_ERROR_PARSING_ELEMENT;
  question_ = pElement->GetText();

  pElement = node->FirstChildElement("Evidence");
  if (pElement == nullptr) return XML_ERROR_PARSING_ELEMENT;
  evidence_ = pElement->GetText();

  pElement = node->FirstChildElement("Keywords");
  if (pElement == nullptr) return XML_ERROR_PARSING_ELEMENT;
  keywords_ = pElement->GetText();

  pElement = node->FirstChildElement("Indicator");
  if (pElement == nullptr) return XML_ERROR_PARSING_ELEMENT;
  indicator_ = pElement->GetText();

  /*
  pElement = node->FirstChildElement("Indicator");
  if (pElement == nullptr) {
    vcl_cout<<"Indicator missing"<<vcl_endl;
    indicator_ = "XXX";
  }
  */
  return XML_SUCCESS;
}

void 
rti_question::write_xml_node(XMLDocument& xmlDoc, XMLElement* node, int index)
{
  //store some data attributes
  node->SetAttribute("std",std_);
  node->SetAttribute("points",points_);
  switch (type_) {
    case R : node->SetAttribute("type","R"); break;
    case LW : node->SetAttribute("type","LW"); break;
    case RW : node->SetAttribute("type","RW"); break;
  }
  node->SetAttribute("ID", index);

  //store others as elements
  XMLElement * pElement = xmlDoc.NewElement("Text");
  pElement->SetText(question_.c_str());
  node->InsertEndChild(pElement);

  pElement = xmlDoc.NewElement("Indicator");
  pElement->SetText(indicator_.c_str());
  node->InsertEndChild(pElement);

  pElement = xmlDoc.NewElement("Evidence");
  pElement->SetText(evidence_.c_str());
  node->InsertEndChild(pElement);

  pElement = xmlDoc.NewElement("Keywords");
  pElement->SetText(keywords_.c_str());
  node->InsertEndChild(pElement);
}