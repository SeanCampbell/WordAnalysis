//:
// \file
// \brief defines the structure of a short-answer question
// \author Charlene Tsai
// \date June 2015

#ifndef rti_question_multiple_choice_h_
#define rti_question_multiple_choice_h_

#include <vcl_string.h>
#include <vcl_vector.h>
#include <emulation/vcl_pair.h>
#include <tinyxml2/tinyxml2.h>
#include <rti/rti_question.h>

class rti_question_multiple_choice: public rti_question
{
public:
  rti_question_multiple_choice(){}
  rti_question_multiple_choice(Q_TYPE in_type, const vcl_string& in_question, int in_std, char in_answer, const vcl_string& in_evidence = "XXX", const vcl_string& keywords = "XXX", const vcl_string& in_indicator = "XXX" );
  virtual ~rti_question_multiple_choice(){}

  virtual XMLError read_xml_node(XMLElement* root_node);
  virtual void write_xml_node(XMLDocument& xmlDoc, XMLElement* root_node, int index);

  vcl_vector<vcl_pair<char,vcl_string> > const & choices() const {return choices_;}
  void add_choice(char choice, const vcl_string& text); 
  bool correct_answer(char choice) const; 
  char answer() const {return answer_;}
  bool get_choice(char choice, vcl_string& text) const; //case sensitive, assuming capital letter

private:
  vcl_vector<vcl_pair<char,vcl_string> > choices_; //for example <'A', "The text for this choice.">
  char answer_;
};

# endif