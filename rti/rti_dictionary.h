//:
// \file
// \brief defines dictionary containing a collection of words in the book database
// \author Charlene Tsai
// \date May 2015
// \updated file Chelsea Ramsingh
// \date March 2016

#ifndef rti_dictionary_h_
#define rti_dictionary_h_

#include <vcl_string.h>
#include <vcl_vector.h>
#include <vbl/vbl_ref_count.h>
#include <tinyxml2/tinyxml2.h>
#include <rti/rti_word_sptr.h>

using namespace tinyxml2;
#ifndef XMLCheckResult
	#define XMLCheckResult(a_eResult) if (a_eResult != XML_SUCCESS) { vcl_cout<<"Error: "<<a_eResult<<vcl_endl; return a_eResult; }
#endif

//: Defines the word record  
class rti_dictionary: public vbl_ref_count
{
public:
  rti_dictionary();
  ~rti_dictionary();
  
public:
  bool find(const vcl_string& word, int& pos); //find position for the exact search or the position the word should be found.
	void insert(rti_word_sptr word, int idx); //successful insertion if entries are complete

    bool valid() const {return is_valid_;}
    size_t size() const {return words_.size();}
	void compute_PSegAves();
	void compute_BiphAves();
	void compute_neighbors(rti_word_sptr target_word, int starting_index = 0); //compute neighbors of a given word. It's neighbors's neighbors are updated too
    void compute_neighbors(); //compute neighbors for all words in the dictionary
    bool import_dictionary(rti_dictionary *other_dictionary, bool *up_to_date);

    // New methods
    void add_missing_words(rti_dictionary *other_dictionary);
    rti_word_sptr get(vcl_string spelling);
    std::vector<rti_word_sptr> get_words();
    void display_message();
    XMLError display_list(const vcl_string& filename);
    //

    XMLError read_xml(const vcl_string& xml_filename);
	XMLError write_xml(vcl_string vxl_filename, bool up_to_date);
    rti_word_sptr& operator[](std::size_t idx) { return words_[idx]; }
    const rti_word_sptr& operator[](std::size_t idx) const { return words_[idx]; }

private:
  void push_back(rti_word_sptr word); //insertion at the end of the word list

private:
  bool is_empty_;
  bool is_valid_;
  vcl_vector<rti_word_sptr> words_;
};


#endif 
