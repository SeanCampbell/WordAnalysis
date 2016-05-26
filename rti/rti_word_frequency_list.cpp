#include "rti_word_frequency_list.h"
#include <vcl_iostream.h>
#include <tinyxml2/tinyxml2.h>

bool greaterThan(std::pair<vcl_string, int> const & a, std::pair<vcl_string, int> const & b)
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
int rti_word_frequency_list::add_word_in_grade_level(vcl_string word, int count, rti_book::AGE gradeLevel)
{
    int index = get_index_from_grade_level(gradeLevel);
    if (index == -1)
        return -1;

    totalWords += count;
    vcl_map<vcl_string, int>::iterator it = gradeLevelMaps[index].find(word);
    if (it != gradeLevelMaps[index].end()) {
        it->second += count;
        return it->second;
    } else {
        gradeLevelMaps[index].insert(std::pair<vcl_string, int>(word, count));
        return count;
    }
}

void rti_word_frequency_list::update_most_frequent_words()
{
    int i;

    vcl_map<vcl_string, int> frequencyGradeLevelMaps[5];
    for (i = 0; i < 5; i++)
    {
        //frequencyGradeLevelMaps[i].clear();
        frequencyGradeLevelMaps[i].insert(gradeLevelMaps[i].begin(), gradeLevelMaps[i].end());
    }

    // For each grade level...
    for (i = 0; i < 5; i++)
    {
        // Clear out old information.
        frequencyGradeLevelLists[i].clear();
        vcl_map<vcl_string, int> map = frequencyGradeLevelMaps[i];
        frequencyGradeLevelLists[i].reserve(map.size());
        // Copy everything over from the frequency map. The words in younger grades are
        // removed from the older grades' maps, so we are guaranteed unique words.
        for (vcl_map<vcl_string, int>::iterator it = map.begin(); it != map.end(); ++it)
            frequencyGradeLevelLists[i].push_back(*it);
        // Sort with highest frequency words at the beginning.
        std::sort(frequencyGradeLevelLists[i].begin(), frequencyGradeLevelLists[i].end(), greaterThan);
        // Shrink to the number of words we want.
        frequencyGradeLevelLists[i].resize(threshold_);
        // Remove words in this grade from all higher grades.
        for (vcl_vector<std::pair<vcl_string, int> >::iterator it = frequencyGradeLevelLists[i].begin(); it != frequencyGradeLevelLists[i].end(); ++it)
            for (int j = i; j < 5; j++)
                frequencyGradeLevelMaps[j].erase(it->first);
    }
}

double *rti_word_frequency_list::normalized_frequencies_in_grade_level(rti_book::AGE gradeLevel)
{
    // If they give an invalid grade level, return NULL.
    int index = get_index_from_grade_level(gradeLevel);
    if (index == -1)
        return NULL;
    // If the map is empty, return NULL.
    double *frequencies = new double[5];
    vcl_map<vcl_string, int> map = gradeLevelMaps[index];
    if (map.size() == 0)
    {
        frequencies[0] = frequencies[1] = frequencies[2] = frequencies[3] = frequencies[4] = 0.0;
        return frequencies;
    }

    int i;
    // Initialize all frequencies to 0.
    for (i = 0; i < 5; i++)
        frequencies[i] = 0.0;
    int totalWordCount = 0;

    // For each word in the given grade level map...
    for (vcl_map<vcl_string, int>::iterator it = map.begin(); it != map.end(); it++)
    {
        // Add the frequency to the total word count.
        totalWordCount += it->second;
        // Check if the word is in any of the most frequent word lists.
        for (i = 0; i < 5; i++)
        {
            // If it's in the grade level, add its counts to
            // the frequency of words in that grade level.
            bool found = false;
            for (vcl_vector<std::pair<vcl_string, int> >::iterator searchIt = frequencyGradeLevelLists[i].begin();
                 searchIt != frequencyGradeLevelLists[i].end();
                 ++searchIt)
            {
                if (searchIt->first == it->first)
                {
                    found = true;
                    break;
                }
            }
            if (found)
            {
                frequencies[i] += it->second;
                // Break out of the loop early. A given
                // word should be in at most one most
                // frequent word list.
                break;
            }
        }
    }

    // Divide all counts by total count
    // to normalize the frequency.
    for (i = 0; i < 5; i++)
        frequencies[i] /= totalWordCount;
    return frequencies;
}

vcl_vector<vcl_string> rti_word_frequency_list::words_in_grade_level(rti_book::AGE gradeLevel) const
{
    vcl_vector<vcl_string> words;
    int index = get_index_from_grade_level(gradeLevel);
    if (index == -1)
        return words;

    vcl_map<vcl_string, int> map = gradeLevelMaps[index];
    for (vcl_map<vcl_string, int>::iterator it = map.begin(); it != map.end(); it++)
        words.push_back(it->first);

    return words;
}

vcl_vector<vcl_string> rti_word_frequency_list::most_frequent_words_in_grade_level(rti_book::AGE gradeLevel, int count) const
{
    vcl_vector<std::pair<vcl_string, int> > wordPairList = frequencyGradeLevelLists[get_index_from_grade_level(gradeLevel)];
    vcl_vector<vcl_string> frequentWordList;

    // Put just words into new list.
    for (int i = 0; i < std::min((int)wordPairList.size(), count); i++)
        frequentWordList.push_back(wordPairList[i].first);
    // Sort by spelling.
    std::sort(frequentWordList.begin(), frequentWordList.end());
    return frequentWordList;
}

XMLError rti_word_frequency_list::write_xml(vcl_string xml_filename)
{
    XMLDocument xmlDoc;
    XMLElement *rootNode = xmlDoc.NewElement("WordFrequencyList");
    rootNode->SetAttribute("threshold", threshold_);
    xmlDoc.InsertFirstChild(rootNode);

    int gradeLevelWordCount;
    for (int i = 0; i < 5; i++)
    {
        XMLElement *glElement = xmlDoc.NewElement("Grade");
        switch (i)
        {
            case 0:
                glElement->SetAttribute("level", "NS/PK/K");
                break;
            case 1:
                glElement->SetAttribute("level", "G1");
                break;
            case 2:
                glElement->SetAttribute("level", "G2");
                break;
            case 3:
                glElement->SetAttribute("level", "G3");
                break;
            case 4:
                glElement->SetAttribute("level", "G4");
                break;
        }

        XMLElement *wsElement = xmlDoc.NewElement("Words");
        wsElement->SetAttribute("unique_words", (int)gradeLevelMaps[i].size());
        glElement->InsertFirstChild(wsElement);
        // We need to add up all words in the grade level.
        vcl_map<vcl_string, int> map = gradeLevelMaps[i];
        gradeLevelWordCount = 0;
        for (vcl_map<vcl_string, int>::iterator it = map.begin(); it != map.end(); it++)
            gradeLevelWordCount += it->second;
        wsElement->SetAttribute("total_count", gradeLevelWordCount);
        // Now we're looking only at the most frequent words.
        vcl_vector<std::pair<vcl_string, int> > vector = frequencyGradeLevelLists[i];
        for (vcl_vector<std::pair<vcl_string, int> >::iterator it = vector.begin(); it != vector.end(); it++)
        {
            XMLElement *wElement = xmlDoc.NewElement("W");
            wElement->SetText(it->first.c_str());
            wElement->SetAttribute("freq", it->second);
            wsElement->InsertEndChild(wElement);
        }
        rootNode->InsertEndChild(glElement);
    }

    XMLError eResult = xmlDoc.SaveFile(xml_filename.c_str());
    XMLCheckResult(eResult);
    return eResult;
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
