#include <rti/rti_assessment.h>
#include <vcl_sstream.h>
#include <vcl_iostream.h>
#include <vul/vul_string.h>

XMLError 
rti_assessment::read_xml(const vcl_string& xml_filename)
{
	XMLDocument xmlDoc;
    
  //Parse the resource
  XMLError eResult = xmlDoc.LoadFile( xml_filename.c_str() );
  XMLCheckResult(eResult);

	/*Get the root element node */
  XMLElement * pRoot = xmlDoc.RootElement();
  if (pRoot == nullptr) return XML_ERROR_FILE_READ_ERROR;
  class_id_ = pRoot->Attribute("classID");
  test_id_ = pRoot->Attribute("testID");
  month_ = pRoot->Attribute("month");
  int size;
  eResult = pRoot->QueryIntAttribute("classSize", &size);
  XMLCheckResult(eResult);
  
  //read the records
  records_.reserve(size);
  XMLElement* pElement = pRoot->FirstChildElement("Records");
  XMLElement * sElement = pElement->FirstChildElement("Student");
  for (int i = 0; i<size; i++) {
    vcl_string s_id, result = vcl_string("");
    s_id = sElement->Attribute("ID");
    XMLElement * qElement = sElement->FirstChildElement("Q");
    while (qElement != nullptr) {
      result = result + qElement->GetText();
      qElement = qElement->NextSiblingElement("Q");
    }
    records_.push_back(vcl_pair<vcl_string, vcl_string>(s_id,result));
    sElement = sElement->NextSiblingElement("Student");
  }
  
  return XML_SUCCESS;
}

XMLError 
rti_assessment::write_xml(vcl_string xml_filename)
{
  XMLDocument xmlDoc;
  XMLElement* root_node = xmlDoc.NewElement( "Assessment" );
  root_node->SetAttribute("month",month_.c_str());  
  root_node->SetAttribute("classSize",(int)records_.size());
  root_node->SetAttribute("testID",test_id_.c_str());
  root_node->SetAttribute("classID",class_id_.c_str());

  xmlDoc.InsertFirstChild( root_node );

  // write out the records 
  XMLElement* pElement = xmlDoc.NewElement("Records");
  for (unsigned int i = 0; i<records_.size(); i++) {
    XMLElement * sElement = xmlDoc.NewElement("Student");
    sElement->SetAttribute("ID",records_[i].first.c_str());
    for (unsigned int j = 0; j<records_[i].second.size(); j++) {
      XMLElement * qElement = xmlDoc.NewElement("Q");
      qElement->SetAttribute("item",j+1);
      vcl_stringstream cc;
      vcl_string choice;  
      cc << records_[i].second[j];
      cc >> choice;
      qElement->SetText((vul_string_upcase(choice)).c_str());
      sElement->InsertEndChild(qElement);
    }
    pElement->InsertEndChild(sElement);
  }
  root_node->InsertEndChild(pElement);

  XMLError eResult = xmlDoc.SaveFile( xml_filename.c_str() );
  XMLCheckResult(eResult);
  return eResult;
}