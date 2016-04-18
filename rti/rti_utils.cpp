#include <vector>
#include <sstream>

#include <vcl_vector.h>
#include <vcl_algorithm.h>
#include <vcl_string.h>
#include <vcl_fstream.h>
#include <vcl_sstream.h>
#include <emulation/vcl_pair.h>

#include <vul/vul_arg.h>
#include <vul/vul_string.h>
#include <vul/vul_reg_exp.h>
#include <vul/vul_reg_exp.h>

#include "rti_literature_sptr.h"
#include "rti_literature.h"
#include "rti_word.h"
#include "rti_dictionary.h"
#include "rti_dictionary_sptr.h"
#include "rti_book.h"
#include "rti_book_sptr.h"

#include "rti_utils.h"

namespace rti_utils
{
    std::string join(std::vector<std::string> v, std::string delimiter)
    {
	std::stringstream ss;
	for (std::vector<std::string>::iterator it = v.begin(); it != v.end(); it++)
	{
	    if (it != v.begin())
		ss << delimiter;
	    ss << *it;
	}
	return ss.str();
    }

    vcl_string trim(const vcl_string& str)
    {
	size_t first = str.find_first_not_of(' ');
	size_t last = str.find_last_not_of(' ');
	return str.substr(first, (last-first+1));
    }

    bool import_cmu_dictionary(vcl_string cmu_filename, vcl_vector<vcl_pair<vcl_string, vcl_string> >& arpabets)
    {
      vcl_ifstream cmu_stream;
      cmu_stream.open(cmu_filename);
      if (!cmu_stream.is_open()) return false;

      arpabets.reserve(134000);
      vul_reg_exp re("([0-9]+)");
      vcl_string arpabet, line;
      vcl_string spelling;
      while(!cmu_stream.eof()) {
	vcl_getline(cmu_stream, line);
	vcl_stringstream line_str(line);
	line_str>>spelling;
	if (spelling == vcl_string(";;;")) continue; //skip the comment
	vcl_getline(line_str, arpabet);
	if (!re.find(spelling)) {
	  arpabet = trim(arpabet);
	  //arpabets.push_back(vcl_pair<vcl_string, vcl_string>(vul_string_downcase(spelling), arpabet));
	  arpabets.push_back(vcl_pair<vcl_string, vcl_string>(spelling, arpabet)); //keep the upper case
	}
	/*
	cmu_stream>>spelling;
	vcl_getline(cmu_stream, arpabet);
	if (!re.find(spelling)) {
	  arpabet = trim(arpabet);
	  arpabets.push_back(vcl_pair<vcl_string, vcl_string>(vul_string_downcase(spelling), arpabet));
	}
	*/
      }
      return true;
    }

    bool find_arpabet(vcl_string spelling, const vcl_vector<vcl_pair<vcl_string, vcl_string> >& cmu_arpabets, vcl_string& arpabet)
    {
      //find position for the exact search using bisection search (iterative version) or return the position the word should be found.

      vul_string_upcase(spelling); //convert to upper case
      int imax = int(cmu_arpabets.size()-1);
      int imin = 0;
      int idx;
      while (imax >= imin) {
	idx = (imax+imin)/2; // calculate the midpoint for roughly equal partition
	if(cmu_arpabets[idx].first == spelling) {
	  arpabet = cmu_arpabets[idx].second;
	  return true; // key found at index imid
	}
	else if (cmu_arpabets[idx].first < spelling)// determine which subarray to search
	  imin = idx + 1; // change min index to search upper subarray
	else imax = idx - 1; // change max index to search lower subarray
      }

      if (cmu_arpabets[idx].first < spelling) idx++;
      return false;// key was not found
    }


    rti_dictionary *build_dictionary(rti_literature *literature, rti_dictionary *old_dict,
				     vcl_vector<vcl_pair<vcl_string, vcl_string> > cmu_arpabets, bool *up_to_date)
    {
	if (cmu_arpabets.empty())
	    return NULL;

	rti_dictionary *dict = new rti_dictionary();
	rti_word_sptr word;
	//iterate through the book list to collect the words
	int pos;
	//vcl_cout<<"Compiling the dictionary from "<<lit()<<" ..."<<vcl_endl;
	for (unsigned int i=0; i<literature->size(); i++) {
	  rti_book_sptr book = (*literature)[i];
	  for (unsigned int j=0; j<book->size(); j++) {
	    if (dict->find((*book)[j].first, pos)) (*dict)[pos]->increase_frequency((*book)[j].second);
	    else {
	      vcl_string arpabet;
	      if (find_arpabet((*book)[j].first, cmu_arpabets, arpabet)) word = new rti_word((*book)[j].first, (*book)[j].second, arpabet);
	      else {
		word = new rti_word((*book)[j].first,(*book)[j].second);
		vcl_cout<<"\t"<<word->spelling()<<" not found"<<vcl_endl;
		*up_to_date = false;
	      }
	      dict->insert(word, pos);
	    }
	  }
	}

    dict->import_dictionary(old_dict, up_to_date);

	vcl_cout<<"Computing phonotactic information ..."<<vcl_endl;
	dict->compute_PSegAves();
	dict->compute_BiphAves();
	dict->compute_neighbors();

	return dict;
    }


    rti_word_frequency_list *generate_word_frequency_list_from_literature(rti_literature *literature, double frequencyRatioThreshold)
    {
        int i;
        std::vector<rti_book*> gradeLevels[5];

        // Divide into groups by grade level:
        // Nursery/Pre-K/Kindergarten, 1st, 2nd, 3rd, 4th
        for (i = 0; i < literature->size(); i++)
        {
            rti_book *book = (*literature)[i].ptr();
            // Add book to the correct grade level.
            switch (book->age_range())
            {
                case rti_book::NS:
                    gradeLevels[0].push_back(book);
                case rti_book::PK:
                    gradeLevels[0].push_back(book);
                case rti_book::K:
                    gradeLevels[0].push_back(book);
                case rti_book::G1:
                    gradeLevels[1].push_back(book);
                case rti_book::G2:
                    gradeLevels[2].push_back(book);
                case rti_book::G3:
                    gradeLevels[3].push_back(book);
                case rti_book::G4:
                    gradeLevels[4].push_back(book);
            }
        }

        rti_word_frequency_list *wflist = new rti_word_frequency_list;
        // For each grade level...
        for (i = 0; i < 5; i++)
        {
            int totalWords = 0;
            std::map<std::string, int> wordMap;
            // Go through each word in each book...
            for (int j = 0; j < gradeLevels[i].size(); j++)
            {
                rti_book *book = gradeLevels[i].at(j);
                for (int k = 0; k < book->size(); k++)
                {
                    vcl_pair<std::string, int> wordFreqPair = (*book)[k];
                    bool check = false;
                    //Check to see if word exists in previous lists
                    for(int n = 0; n < i, n++)
                    {
                    	
                    	std::map<std::string, int>::iterator it1 = gradeLevelMaps[n].find(wordFreqPair->first);
		    	if(it1 != gradeLevelMaps[n].end())
		        {
			 	//element found;
   			 	check = true;
		    	}
                    }
                    if(check == false)
                    {
                    	std::map<std::string, int>::iterator it2 = wordMap.find(wordFreqPair->first);
                    	int x;
                    	if(it2 != wordMap.end())
                    	{
                    		//element found
                    		x = it2 -> second += (wordFreqPair-> second);
                    	}
                    	else
                    	{
                    		wordMap.insert(wordFreqPair);
                    	}
                    }
                }
            }
            wflist->gradeLevelMaps[i] = wordMap;
        }

        return wflist;

        /*
            For each grade level...
                Go through each word in each book
                    Check if word is in previous grade level lists
                    If not, tally occurrences of word in master map
                Add # of occurrences to tally of total # of words
                Calculate expected frequency of each word
                For each word in map...
                    Calculate normalized frequency by dividing by # of words in grade level
                    Compare to expected frequency – if ratio is greater than a given
                    parameter, add to list of words for that grade level
        */
    }

}

