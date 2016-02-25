//:
// \file
// \brief defines the word record in the dictionary
// \author Charlene Tsai
// \date May 2015

#ifndef rti_word_h_
#define rti_word_h_

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
class rti_word: public vbl_ref_count
{
public:
  rti_word()
    :spelling_(""), arpabet_("XXX"), morphemes_str_("XXX"), is_func_(false), frequency_(0), psa_(0), bipha_(0), syllables_(0){};
  rti_word(const vcl_string& in_word, int in_freq, const vcl_string& in_arpabet="XXX", const vcl_string& in_morpheme = "XXX",  bool in_fun = false, float in_psa = 0, float in_bipha=0); 
  ~rti_word(){};
  
  bool valid() const; 
  vcl_string const & spelling() const {return spelling_;}
  vcl_string const & arpabet() const {return arpabet_;}
  vcl_string const & arpabet_no_stresses() const {return arpabet_no_stresses_;}
  vcl_vector<vcl_string> const& phonemes() const{ return phonemes_;}
  vcl_string const & morphemes() const {return morphemes_str_;}
  bool is_function() const {return is_func_;}
  int frequency() const {return frequency_;} 
  int syllables() const {return syllables_;}
  unsigned int size() const {return (int)phonemes_.size();}
  double psa() const {return psa_;}
  double bipha() const {return bipha_;}
  vcl_vector<vcl_string> const & neighbors() const {return neighbors_;} 
  void increase_frequency(int & increment) {frequency_ += increment;}
  void set_psa(float in_psa) {psa_ = in_psa;}
  void set_bipha(float in_bipha) {bipha_ = in_bipha;}
  void set_morphemes(const vcl_string & in_morphemes);
  void add_neighbor(const vcl_string& str) {neighbors_.push_back(str);}
  XMLError read_xml_node(XMLElement* root_node);
  void write_xml_node(XMLDocument& xmlDoc, XMLElement* root_node);
  void copy_arpabet_morpheme(rti_word_sptr old); //copy everything related to arpabet and morpheme
  void reset_arpabet_morpheme(); //clear up all components related to arpabet and morpheme
 
private:
  void decompose(const vcl_string& in_str, vcl_vector<vcl_string>& components);
  void destress_arpabet(vcl_vector<vcl_string>& phonemes, vcl_vector<int>& stresses);
  void initialize();

private:
  vcl_string spelling_; //all in lower case
  vcl_string arpabet_;
  vcl_string arpabet_no_stresses_;
  vcl_vector<vcl_string> phonemes_; //no stresses
  vcl_vector<int> stresses_; //each phoneme position is recorded with the stress number. -1 for consonant
  vcl_string morphemes_str_;
  vcl_vector<vcl_string> morphemes_;
  int syllables_;
  bool is_func_;
  int frequency_;
  float psa_; //positional segment average
  float bipha_; //biphone average
  vcl_vector<vcl_string> neighbors_; // words that differ from the target word by one phoneme substitution, addition or deletion.
};


#endif 
