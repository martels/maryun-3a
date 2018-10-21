#if (0)

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class Dictionary
{
private:
	vector<string> alphabet = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
	vector<string> dictionary;
public:
	Dictionary();
	friend ostream& operator<< (ostream& ostr, const Dictionary& rhs);
	void sort();
	int search(string input);
};

class Grid
{
public:
	vector<int>* grid;
	Grid();

};
#endif