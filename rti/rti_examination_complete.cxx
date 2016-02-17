#include <vcl_iostream.h>
#include <rti/rti_examination_complete.h>
#include <rti/rti_question_sptr.h>
#include <rti/rti_question_multiple_choice.h>

XMLError 
rti_examination_complete::read_xml(const vcl_string& xml_filename)
{
  questions_.clear();
  essays_.clear();

	XMLDocument xmlDoc;
    
  //Parse the resource
  XMLError eResult = xmlDoc.LoadFile( xml_filename.c_str() );
  XMLCheckResult(eResult);

	/*Get the root element node */
  XMLElement * pRoot = xmlDoc.RootElement();
  if (pRoot == nullptr) return XML_ERROR_FILE_READ_ERROR;
  id_ = pRoot->Attribute("ID");

  essays_.reserve(10);
  questions_.reserve(50);
  XMLElement* pElement = pRoot->FirstChildElement("Essay");
  while (pElement != nullptr) {
    //read in the word counts for the story
    XMLElement* bElement = pElement->FirstChildElement("Story");
    rti_book_sptr story;
    if (bElement != nullptr) {
        story= new rti_book();
        story->read_xml_node(bElement);
    }
    //read in the associated questions
    int q_count = 0;
    XMLElement* qElement = pElement->FirstChildElement("Question");
    while (qElement != nullptr) {
      rti_question_sptr question; 
      vcl_string type = qElement->Attribute("type");
      if (type == vcl_string("R")) question = new rti_question_multiple_choice();
      else question = new rti_question();
      question->read_xml_node(qElement);
      questions_.push_back(question);
      q_count++;
      qElement = qElement->NextSiblingElement("Question");
    }
    essays_.push_back(vcl_pair<rti_book_sptr,int>(story,q_count));
    pElement = pElement->NextSiblingElement("Question");
  }
  return XML_SUCCESS;
}
	
XMLError 
rti_examination_complete::write_xml(vcl_string xml_filename)
{
  XMLDocument xmlDoc;
  XMLElement* root_node = xmlDoc.NewElement( "ELA_Examination" );
  root_node->SetAttribute("questions", (int)questions_.size());  
  root_node->SetAttribute("ID", id_.c_str());
  xmlDoc.InsertFirstChild( root_node );

  int q_count = 0;
  for (unsigned int i = 0; i<essays_.size(); i++) {
    XMLElement * wElement = xmlDoc.NewElement("Essay");
    //insert the word count of the story
    XMLElement * eElement = xmlDoc.NewElement("Story");
    essays_[i].first->write_xml_node(xmlDoc, eElement);
    wElement->InsertEndChild(eElement);
    //insert the questions following the story
    for (unsigned int j = 0; j<essays_[i].second; j++) {
      XMLElement * qElement = xmlDoc.NewElement("Question");
      questions_[q_count]->write_xml_node(xmlDoc, qElement, q_count+1);
      wElement->InsertEndChild(qElement);
      q_count++;
    }
    root_node->InsertEndChild(wElement);
  }

  XMLError eResult = xmlDoc.SaveFile( xml_filename.c_str() );
  XMLCheckResult(eResult);
  return eResult;
}
