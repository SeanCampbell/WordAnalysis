//:
// \file
// \brief defines the structure of a question
// \author Charlene Tsai
// \date June 2015

#ifndef rti_question_h_
#define rti_question_h_

#include <vcl_string.h>
#include <vbl/vbl_ref_count.h>
#include <tinyxml2/tinyxml2.h>

using namespace tinyxml2;
#ifndef XMLCheckResult
	#define XMLCheckResult(a_eResult) if (a_eResult != XML_SUCCESS) { vcl_cout<<"Error: "<<a_eResult<<vcl_endl; return a_eResult; }
#endif

enum Q_TYPE {R, LW, RW}; 

//: Defines the word record  
class rti_question: public vbl_ref_count
{
public:
  rti_question(){}
  rti_question(Q_TYPE in_type, const vcl_string& in_question, int in_std, int in_points, const vcl_string& in_evidence = "XXX", const vcl_string& in_keywords = "XXX", const vcl_string& in_indicator = "XXX")
    : type_(in_type), question_(in_question), std_(in_std), points_(in_points), evidence_(in_evidence), keywords_(in_keywords), indicator_(in_indicator) {}
  virtual ~rti_question(){}

  Q_TYPE type() const {return type_;}
  vcl_string const & question () const {return question_;}
  vcl_string const & evidence () const {return evidence_;}
  vcl_string const & indicator () const {return indicator_;}
  int standard() const {return std_;}
  int points() const {return points_;}

  virtual XMLError read_xml_node(XMLElement* root_node);
  virtual void write_xml_node(XMLDocument& xmlDoc, XMLElement* node, int index);

protected:
  Q_TYPE type_;
  vcl_string question_;
  vcl_string indicator_;
  vcl_string evidence_;
  vcl_string keywords_;
  int std_;
  int points_;
};

#endif 