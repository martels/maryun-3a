#include "dictionary.h"

using namespace std;

ostream& operator<< (ostream& ostr, const Dictionary& rhs)
{
	size = dictionary.size();
	for(int i = 0; i < size; i++)
	{
		ostr << dictionary.at(i) << endl;
	}
	return ostr;
}

Dictionary::Dictionary()
{
	ifstream dictionaryfile;
	dictionaryfile.open("dictionary.txt");

	//Error Checking
	if(dictionaryfile.fail())
	{
		cerr << "Error opening file" << endl;
		exit(1);
	}

	while()
	{
		
	}

}

void Dictionary::sort()
{

}

int Dictionary::search(string input)
{

}

Grid::Grid();
{

}