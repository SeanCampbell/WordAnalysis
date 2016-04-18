/*
 * Frequency.h
 *
 *  Created on: Apr 11, 2016
 *      Author: Brandon
 */

#ifndef FREQUENCY_H_
#define FREQUENCY_H_

#include <rti_word.h>
#include <algorithm>
#include <vector>
#include <StateList.h>

class Frequency
{
	public:

	    rti_word getTopNum(int x, rti_word wordList[] ); //x is the size number of words requested
		rti_word compareLists(rti_word stateList[], rti_word gradeList[]);

	private:

		rti_word Frequency::bubbleSort(int y, rti_word words[]) //bubble sort y iterations
		{
			int i;
			int j;
			for(i=0;i<y;i++)
			{
				for(j=i;j<sizeof(words); j++)
				{
					if(words[j].frequency() > words[i].frequency())
					{
						rti_word temp = words[i];
						words[i] = words[j];
						words[j] = temp;
					}
				}
			}
			return words;
		}
};

rti_word Frequency::getTopNum(int x, rti_word wordList[] ) //x is the size number of words requested
{
	rti_word words[x];
	bubbleSort(x,wordList);
	int i;
	for(i=0; i<x;i++)
	{
		words[i] = wordList[i];
	}
	return words;
}

std::vector<rti_word> Frequency::compareLists(rti_word stateList[], rti_word gradeList[])
{
		//perform a set difference on the two lists (cplusplus.com)
		//return the resulting list
		std::vector<rti_word> v;
		
		rti_word temp;
		
		int i,n;
		
		bool notFound;
		for(i=0; i<sizeof stateList;i++)
		{
			temp = stateList[i];
			notFound = false;
			for(n=0;n<sizeof gradeList;n++)
			{
				if(gradeList[n].spelling() == temp)
				{
					notFound = false;
					break;
				}
				else
				{
					notFound = true;
				}
			}
			if(notFound == true)
			{
				v.push_back(temp);
			}
		}
		return v;
		
std::vector<rti_word> Frequency::compareListsGrade(rti_word stateList[], rti_word gradeList[])
{		std::vector<rti_word> c;
		rti_word other;
		int j,k;
		
		bool notFound;
		for(j=0; j<sizeof gradeList; j++)
		{
			other = gradeList[j];
			notFound = false;
			for(k=0; k<sizeof stateList; k++)
			{
				if(gradeList[k].spelling() == other)
				{
					notFound = false;
					break;
				}
				else
				{
					notFound = true;
				}
			}
			if(notFound == true)
			{
				c.push_back(other);	
			}
		}
		return c;

std::vector<rti_word> Frequency::findSimilarWords(rti_word stateList[], rti_word gradeList[])
{		
	std::vector<rti_word> k;
	std::sort(stateList.begin(), stateList.end());
    	std::sort(gradeList.begin(), gradeList.end());
    		std::set_intersection(stateList.begin(), stateList.end(),
                          gradeList.begin(), gradeList.end(),
                          std::back_inserter(k));
}
	return k;
		//std::vector<int>::iterator it;
		//it=std::set_difference(stateList[0],stateList[sizeof stateList],gradeList[0],gradeList[sizeof gradeList],v.begin());
}

#endif /* FREQUENCY_H_ */
