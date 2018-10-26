#ifndef DICTIONARY_H
#define	DICTIONARY_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Dictionary
{
private:
	vector<string> dictionary;
public:
    Dictionary();
    int length;
    void sort();
    bool search(int first, int last, string key);
	friend ostream& operator<< (ostream& ostr, const Dictionary& rhs);
};

#endif /* Dictionary_h */
