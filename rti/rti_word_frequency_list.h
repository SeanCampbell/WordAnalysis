//:
// \file
// \author Brandon Gratta
// \date   April 2016

#ifndef RTI_WORD_FREQUENCY_LIST_H
#define RTI_WORD_FREQUENCY_LIST_H

#include <vcl_vector.h>
#include <vcl_map.h>
#include <tinyxml2/tinyxml2.h>
#include "rti/rti_book.h"

class rti_word_frequency_list
{
public:
    rti_word_frequency_list();
    void set_threshold(double t) { threshold_ = t; }
    double threshold() const { return threshold_; }
    int add_word_in_grade_level(vcl_string word, int count, rti_book::AGE gradeLevel);
    void update_most_frequent_words();
    int total_number_of_words() const { return totalWords; }
    double *normalized_frequencies_in_grade_level(rti_book::AGE gradeLevel) const;
    vcl_vector<vcl_string> words_in_grade_level(rti_book::AGE gradeLevel) const;
    vcl_vector<vcl_string> most_frequent_words_in_grade_level(rti_book::AGE gradeLevel, int count) const;
    //XMLError read_xml(const vcl_string &xml_filename);
    XMLError write_xml(vcl_string xml_filename);

private:
    int get_index_from_grade_level(rti_book::AGE gradeLevel) const;
    vcl_map<vcl_string, int> gradeLevelMaps[5];
    vcl_map<vcl_string, int> frequencyGradeLevelMaps[5];
    int totalWords;
    double threshold_;
};

#endif // RTI_WORD_FREQUENCY_LIST_H
