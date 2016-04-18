#include "rti_word_frequency_list.h"

rti_word_frequency_list::rti_word_frequency_list()
{
    for (int i = 0; i < 3; i++) {
        gradeLevelMaps[i].insert(std::pair<std::string, int>("a", 0));
        gradeLevelMaps[i].insert(std::pair<std::string, int>("an", 0));
        gradeLevelMaps[i].insert(std::pair<std::string, int>("but", 0));
        gradeLevelMaps[i].insert(std::pair<std::string, int>("cat", 0));
        gradeLevelMaps[i].insert(std::pair<std::string, int>("puppy", 0));
    }
    for (int i = 3; i < 5; i++) {
        gradeLevelMaps[i].insert(std::pair<std::string, int>("a", 0));
        gradeLevelMaps[i].insert(std::pair<std::string, int>("and", 0));
        gradeLevelMaps[i].insert(std::pair<std::string, int>("but", 0));
        gradeLevelMaps[i].insert(std::pair<std::string, int>("dog", 0));
        gradeLevelMaps[i].insert(std::pair<std::string, int>("puppy", 0));
    }
}

std::vector<std::string> rti_word_frequency_list::words_in_grade_level(rti_book::AGE gradeLevel)
{
    int index;
    switch (gradeLevel)
    {
        case rti_book::NS:
            index = 0;
        case rti_book::PK:
            index = 0;
        case rti_book::K:
            index = 0;
        case rti_book::G1:
            index = 1;
        case rti_book::G2:
            index = 2;
        case rti_book::G3:
            index = 3;
        case rti_book::G4:
            index = 4;
    }

    std::vector<std::string> words;
    for (std::map<std::string, int>::iterator it = gradeLevelMaps[index].begin(); it != gradeLevelMaps[index].end(); it++)
        words.push_back(it->first);

    return words;
}

/*
std::vector<std::string> rti_word_frequency_list::get_most_frequent_words(int count)
{

}
*/
