//:
// \file
// \brief defines the data structure for ELA exam containing the word counts for essays
// \author Charlene Tsai
// \date June 2015

#ifndef rti_examination_complete_h_
#define rti_examination_complete_h_

#include <vcl_string.h>
#include <vcl_vector.h>
#include <vbl/vbl_ref_count.h>
#include <tinyxml2/tinyxml2.h>
#include <emulation/vcl_pair.h>
#include <rti/rti_question_sptr.h>
#include <rti/rti_question.h>
#include <rti/rti_examination.h>
#include <rti/rti_book_sptr.h>
#include <rti/rti_book.h>

using namespace tinyxml2;
#ifndef XMLCheckResult
	#define XMLCheckResult(a_eResult) if (a_eResult != XML_SUCCESS) { vcl_cout<<"Error: "<<a_eResult<<vcl_endl; return a_eResult; }
#endif


//: Defines the word record  
class rti_examination_complete: public rti_examination
{
public:
  rti_examination_complete() {}
  rti_examination_complete(vcl_string in_id):rti_examination(in_id) {}
  ~rti_examination_complete(){}

  void add_essay(rti_book_sptr essay, int q_count) {essays_.push_back(vcl_pair<rti_book_sptr,int>(essay, q_count));}
  virtual XMLError read_xml(const vcl_string& xml_filename); 
	virtual XMLError write_xml(vcl_string vxl_filename);
 
protected:
  vcl_vector< vcl_pair<rti_book_sptr, int> > essays_; //the first element is the essay, and the second element is the number of questions
};

#endif 