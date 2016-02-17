//:
// \file
// \brief defines the word record in the dictionary
// \author Charlene Tsai
// \date May 2015

#ifndef rti_book_h_
#define rti_book_h_

#include <vcl_string.h>
#include <vcl_vector.h>
#include <emulation/vcl_pair.h>
#include <vbl/vbl_ref_count.h>
#include <tinyxml2/tinyxml2.h>


using namespace tinyxml2;
#ifndef XMLCheckResult
	#define XMLCheckResult(a_eResult) if (a_eResult != XML_SUCCESS) { vcl_cout<<"Error: "<<a_eResult<<vcl_endl; return a_eResult; }
#endif

enum AGE {NS, PK, K, G1, G2, G3, G4}; 

//: Defines the word record  
class rti_book: public vbl_ref_count
{
public:
  rti_book()
    :title_(vcl_string("")), is_valid_(false) {};
  rti_book(const vcl_string& in_title, const vcl_string& in_author, AGE in_age_range, const vcl_string& text_file); 
  ~rti_book(){}
  
  bool is_valid() const {return is_valid_;}
  vcl_string const & title() const {return title_;}
  vcl_string title_downcase() const;
  vcl_string const & author() const {return author_;}
  AGE const & age_range() const {return age_range_;}
  int word_count() const {return word_count_;} 
  size_t size() const {return words_.size();}
  vcl_pair<vcl_string, int>& operator[](std::size_t idx) { return words_[idx]; }
  const vcl_pair<vcl_string, int>& operator[](std::size_t idx) const { return words_[idx]; }

  XMLError read_xml_node(XMLElement* root_node);
  void write_xml_node(XMLDocument& xmlDoc, XMLElement* root_node);
 

private:
  bool is_valid_;
  vcl_string title_;
  vcl_string author_;
  AGE age_range_;  
  int word_count_;
  vcl_vector< vcl_pair<vcl_string, int> > words_;
};


#endif 
