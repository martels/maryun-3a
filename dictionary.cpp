#include "dictionary.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

Dictionary::Dictionary()
{
	length = 0;
	ifstream dictionaryfile;
	dictionaryfile.open("dictionary.txt");

	//Error Checking
	if(dictionaryfile.fail())
	{
		cerr << "Error opening file" << endl;
		exit(1);
	}
	string str;
	while(getline(dictionaryfile, str)) 
	{
	    if (str.size() > 0) 
	    {
	    	dictionary.push_back(str);
	        length++;
	    }
	}

	dictionaryfile.close();
}



void Dictionary::sort()
{
    int current;
	string temp;
	int length = dictionary.size();
	double percent = 0;

    for(int i = 0; i< length-1; i++)
	{
		current = i;
        for(int j = i+1; j<length; j++)
		{
			if(dictionary[j] < dictionary[current])
			{
				current = j;
			}
		}
		temp = dictionary[i];
		dictionary[i] = dictionary[current];
		dictionary[current] = temp;

		percent = (i*100/length);
		cout << "Sorting(" << percent << "%) \r" << flush;
	}
	cout << "Sorting(100%)" << endl;
	return;
}

bool Dictionary::search(int first, int last, string key)
{
//    int compare;
    
    if (first == last)
    {
    	if(key.compare(dictionary[first]) == 0)
        	return true;
        else
        	return false;
    }
    
	while(first <= last)
	{
		int mid = (first + last) / 2;
        //compare = key.compare(dictionary[mid]);
        //cout << compare << endl;
        
        if(dictionary[mid] == key)
        {
            return true;
        }
        
		else if(key < dictionary[mid])
		{
			last = mid - 1;;
		}
        
		else
		{
            first = mid + 1;
		}
	}
	return false;

 //        if(compare == 0)
 //        {
 //            return true;
 //        }
        
	// 	else if(compare < 0)
	// 	{
	// 		return search(first, mid - 1, key);
	// 	}
        
	// 	else
	// 	{
 //            return search(mid + 1, last, key);
	// 	}
	// }
	// return false;
}


ostream& operator<<(ostream& ostr, const Dictionary& rhs)
{
	int size = rhs.dictionary.size();
	for(int i = 0; i < size; i++)
	{
		ostr << rhs.dictionary.at(i) << endl;
	}
	return ostr;
}


