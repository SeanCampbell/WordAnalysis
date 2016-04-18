#ifndef RTI_WORD_FREQUENCY_LIST_H
#define RTI_WORD_FREQUENCY_LIST_H

#include <cstdlib>
#include <string>
#include <vector>
#include <map>
#include "rti/rti_book.h"

class rti_word_frequency_list
{
public:
    rti_word_frequency_list();
    std::vector<std::string> words_in_grade_level(rti_book::AGE gradeLevel);

    //std::vector<std::string> get_most_frequent_words(int count);

private:
    std::map<std::string, int> gradeLevelMaps[5];
};

#endif // RTI_WORD_FREQUENCY_LIST_H
