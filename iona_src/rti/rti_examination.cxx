#include <vcl_iostream.h>
#include <rti/rti_examination.h>
#include <rti/rti_question_sptr.h>
#include <rti/rti_question_multiple_choice.h>

XMLError 
rti_examination::read_xml(const vcl_string& xml_filename)
{
  questions_.clear();

	XMLDocument xmlDoc;
    
  //Parse the resource
  XMLError eResult = xmlDoc.LoadFile( xml_filename.c_str() );
  XMLCheckResult(eResult);

	/*Get the root element node */
  XMLElement * pRoot = xmlDoc.RootElement();
  if (pRoot == nullptr) return XML_ERROR_FILE_READ_ERROR;
  id_ = pRoot->Attribute("ID");

  //Read the questions
	questions_.reserve(100);
  XMLElement* pElement = pRoot->FirstChildElement("Question");
  while (pElement != nullptr) {
    rti_question_sptr question; 
    vcl_string type = pElement->Attribute("type");
    if (type == vcl_string("R")) question = new rti_question_multiple_choice();
    else question = new rti_question();
    question->read_xml_node(pElement);
    questions_.push_back(question);
    pElement = pElement->NextSiblingElement("Question");
  }
  
  return XML_SUCCESS;
}
	
XMLError 
rti_examination::write_xml(vcl_string xml_filename)
{
  XMLDocument xmlDoc;
  XMLElement* root_node = xmlDoc.NewElement( "ELA_Examination" );
  root_node->SetAttribute("questions", (int)questions_.size());  
  root_node->SetAttribute("ID", id_.c_str());
  xmlDoc.InsertFirstChild( root_node );

  for (unsigned int i = 0; i<questions_.size(); i++) {
    XMLElement * wElement = xmlDoc.NewElement("Question");
    questions_[i]->write_xml_node(xmlDoc, wElement, i+1);
    root_node->InsertEndChild(wElement);
  }

  XMLError eResult = xmlDoc.SaveFile( xml_filename.c_str() );
  XMLCheckResult(eResult);
  return eResult;
}
