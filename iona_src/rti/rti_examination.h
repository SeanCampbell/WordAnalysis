//:
// \file
// \brief defines the datastructure for ELA exam
// \author Charlene Tsai
// \date June 2015

#ifndef rti_examination_h_
#define rti_examination_h_

#include <vcl_string.h>
#include <vcl_vector.h>
#include <vbl/vbl_ref_count.h>
#include <tinyxml2/tinyxml2.h>
#include <rti/rti_question_sptr.h>
#include <rti/rti_question.h>

using namespace tinyxml2;
#ifndef XMLCheckResult
	#define XMLCheckResult(a_eResult) if (a_eResult != XML_SUCCESS) { vcl_cout<<"Error: "<<a_eResult<<vcl_endl; return a_eResult; }
#endif


//: Defines the word record  
class rti_examination: public vbl_ref_count
{
public:
  rti_examination() {}
  rti_examination(vcl_string in_id) {id_ = in_id;}
  ~rti_examination(){}

  vcl_string const& id() const {return id_;}
  void add_question(rti_question_sptr q) {questions_.push_back(q);}
  int size() const {return (int)questions_.size();}

  virtual XMLError read_xml(const vcl_string& xml_filename); 
	virtual XMLError write_xml(vcl_string vxl_filename);

  rti_question_sptr& operator[](std::size_t idx) { return questions_[idx]; }
  const rti_question_sptr& operator[](std::size_t idx) const { return questions_[idx]; }

protected:
  vcl_string id_;
  vcl_vector<rti_question_sptr> questions_;

};

#endif 