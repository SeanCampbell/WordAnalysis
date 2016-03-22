//:
// \file
// \brief defines database for a collection of books
// \author Charlene Tsai
// \date May 2015

#ifndef rti_literature_h_
#define rti_literature_h_

#include <vcl_string.h>
#include <vbl/vbl_ref_count.h>
#include <tinyxml2/tinyxml2.h>
#include <rti/rti_book_sptr.h>
#include <rti/rti_book.h>
#include <vector>

using namespace tinyxml2;
#ifndef XMLCheckResult
	#define XMLCheckResult(a_eResult) if (a_eResult != XML_SUCCESS) { vcl_cout<<"Error: "<<a_eResult<<vcl_endl; return a_eResult; }
#endif

//: Defines the word record  
class rti_literature: public vbl_ref_count
{
public:
  rti_literature();
  ~rti_literature();
  
public:
  bool find(vcl_string isbn, int& pos); //find position for the exact search or the position the book should be found. Search is based on the book isbn.
	void insert(rti_book_sptr book, int idx); //successful insertion if entries are complete
  void replace(rti_book_sptr book, int idx);
//*****New Code  
  void remove(int idx); //remove specified book from library
  rti_book_sptr getBook(vcl_string isbn); //retrieve book with specified ISBN #
  std::vector<rti_book_sptr> getAllBooks(); //retrieve all books that exist in the library
//*****New Code

  XMLError read_xml(const vcl_string& xml_filename); 
	XMLError write_xml(vcl_string vxl_filename);
  size_t size() const {return books_.size(); }
  rti_book_sptr& operator[](std::size_t idx) { return books_[idx]; }
  const rti_book_sptr& operator[](std::size_t idx) const { return books_[idx]; }

private:
  void push_back(rti_book_sptr word); //insertion at the end of the book list

private:
  bool is_empty_;
  vcl_vector<rti_book_sptr> books_;
};

#endif 
