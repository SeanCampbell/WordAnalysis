#include "rti_word_frequency_list.h"

#include <iostream>

bool greaterThan(std::pair<std::string, int> const & a, std::pair<std::string, int> const & b)
{
     return a.second > b.second;
}

rti_word_frequency_list::rti_word_frequency_list()
{
    threshold_ = 10;
}

//
// Public Methods
//
int rti_word_frequency_list::add_word_in_grade_level(std::string word, int count, rti_book::AGE gradeLevel)
{
    int index = get_index_from_grade_level(gradeLevel);
    if (index == -1)
        return -1;

    totalWords += count;
    std::map<std::string, int>::iterator it = gradeLevelMaps[index].find(word);
    if (it != gradeLevelMaps[index].end()) {
        it->second += count;
        return it->second;
    } else {
        gradeLevelMaps[index].insert(std::pair<std::string, int>(word, count));
        return count;
    }
}

void rti_word_frequency_list::update_most_frequent_words()
{
    int i;
    for (i = 0; i < 5; i++)
    {
        frequencyGradeLevelMaps[i].clear();
        frequencyGradeLevelMaps[i].insert(gradeLevelMaps[i].begin(), gradeLevelMaps[i].end());
    }

    // For each grade level...
    for (i = 0; i < 5; i++)
    {
        // Go through every word...
        std::map<std::string, int> map = gradeLevelMaps[i];
        for (std::map<std::string, int>::iterator it = map.begin(); it != map.end(); it++)
        {
            // If the word does not occur frequently enough, remove it.
            if (it->second < threshold_)
                frequencyGradeLevelMaps[i].erase(it->first);
            // Otherwise, erase the word from maps of all higher grade levels.
            else
                for (int j = i+1; j < 5; j++)
                    frequencyGradeLevelMaps[j].erase(it->first);
        }
    }
}

int rti_word_frequency_list::number_of_words_in_grade_level(rti_book::AGE gradeLevel) const
{

}

std::vector<std::string> rti_word_frequency_list::words_in_grade_level(rti_book::AGE gradeLevel) const
{
    std::vector<std::string> words;
    int index = get_index_from_grade_level(gradeLevel);
    if (index == -1)
        return words;

    std::map<std::string, int> map = gradeLevelMaps[index];
    for (std::map<std::string, int>::iterator it = map.begin(); it != map.end(); it++)
        words.push_back(it->first);

    return words;
}

std::vector<std::string> rti_word_frequency_list::most_frequent_words_in_grade_level(rti_book::AGE gradeLevel, int count) const
{
    std::vector<std::pair<std::string, int> > wordPairList;
    std::vector<std::string> frequentWordList;
    std::map<std::string, int> map = frequencyGradeLevelMaps[get_index_from_grade_level(gradeLevel)];

    // Put everything into a vector so we can sort it.
    for (std::map<std::string, int>::iterator it = map.begin(); it != map.end(); it++)
        wordPairList.push_back(*it);
    // Sort by count with highest count at the top.
    std::sort(wordPairList.begin(), wordPairList.end(), greaterThan);
    // Put most frequent in new list.
    for (int i = 0; i < std::min((int)wordPairList.size(), count); i++)
        frequentWordList.push_back(wordPairList[i].first);
    // Sort by spelling.
    std::sort(frequentWordList.begin(), frequentWordList.end());
    return frequentWordList;
}


//
// Private Methods
//
int rti_word_frequency_list::get_index_from_grade_level(rti_book::AGE gradeLevel) const
{
    switch (gradeLevel)
    {
        case rti_book::NS:
            return 0;
        case rti_book::PK:
            return 0;
        case rti_book::K:
            return 0;
        case rti_book::G1:
            return 1;
        case rti_book::G2:
            return 2;
        case rti_book::G3:
            return 3;
        case rti_book::G4:
            return 4;
    }
    return -1;
}

