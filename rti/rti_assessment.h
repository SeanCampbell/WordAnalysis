//:
// \file
// \brief defines the assessment containing the assessment records of each class per assessment
// \author Charlene Tsai
// \date June 2015

#ifndef rti_assessment_h_
#define rti_assessment_h_

#include <vcl_string.h>
#include <vcl_vector.h>
#include <emulation/vcl_pair.h>
#include <vbl/vbl_ref_count.h>
#include <tinyxml2/tinyxml2.h>


using namespace tinyxml2;
#ifndef XMLCheckResult
	#define XMLCheckResult(a_eResult) if (a_eResult != XML_SUCCESS) { vcl_cout<<"Error: "<<a_eResult<<vcl_endl; return a_eResult; }
#endif

//: Defines the word record  
class rti_assessment: public vbl_ref_count
{
public:
  rti_assessment(){};
  rti_assessment(const vcl_string& c_id, const vcl_string& t_id, const vcl_string& month):class_id_(c_id), test_id_(t_id), month_(month){};
  ~rti_assessment(){};
  
public:

  XMLError read_xml(const vcl_string& xml_filename); 
	XMLError write_xml(vcl_string vxl_filename);
  size_t class_size() const {return records_.size();}
  vcl_pair<vcl_string, vcl_string>& operator[](std::size_t idx) { return records_[idx]; }
  const vcl_pair<vcl_string, vcl_string>& operator[](std::size_t idx) const { return records_[idx]; }
  void add_record(const vcl_string& S_ID, const vcl_string& result) {records_.push_back(vcl_pair<vcl_string,vcl_string>(S_ID,result));} 
  const vcl_string& class_id() const {return class_id_;} 
  const vcl_string& test_id() const {return test_id_;}

private:
  vcl_string class_id_;
  vcl_string test_id_;
  vcl_string month_;
  vcl_vector<vcl_pair<vcl_string, vcl_string> > records_; //the first string for student ID, the second string contains a string of answer/point
};


#endif 