#include "dictionary.h"
#include "d_matrix.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

ostream& operator<< (ostream& ostr, const Dictionary& rhs)
{
	size = rhs.dictionary.size();
	for(int i = 0; i < size; i++)
	{
		ostr << rhs.dictionary.at(i) << endl;
	}
	return ostr;
}

ostream& operator<< (ostream& ostr, const Grid& rhs)
{
	for(int i = 0; i < size; i++)
	{
		for(int k = 0; k < size; k++)
		{
			ostr << rhs.grid[k][i] << " ";
		}
		ostr << endl;
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
	string temp;
	while(dictionaryfile >> temp)
	{
		dictionary.push_back(temp);
	}

	dictionaryfile.close();
}

void Dictionary::sort()
{
	string lowest, temp;
	int min;
	int i = dictionary.size();
	int start = 0; 
	while(i != 0)
	{
		lowest = dictionary.at(start);
		for(int k = start; k < i; k++)
		{
			if(dictionary.at(k) < lowest)
			{
				lowest = dictionary.at(k);
				min = k;
			}
		}
		temp = dictionary.at(start);
		dictionary.at(start) = lowest;
		dictionary.at(min) = temp;
		start ++;
	}
}

int Dictionary::search(string input)
{

}

Grid::Grid();
{
	string file;
	int count = 0;
	int temp;
	cout << "Which file would you like to open?" << endl;
	cin >> file;
	while(count < 5) {
	if(file == "input15.txt") {
		size = 15;
		break;
	}
	else if(file == "input30.txt") {
		size = 30;
		break;
	}
	else if(file = "input50.txt") {
		size = 50;
		break;
	}
	else {
		cout << "File could not be openned by this program " << count << " attempts remaining." << endl;
		count++;
	} }

	grid = new matrix(size, size);

	ifstream gridfile;
	gridfile.open(file);

	if(gridfile.fail)
	{
		cerr << "Error opening file" << endl;
		exit(1);
	}

	for(int i = 0; i < size; i++)
	{
		for(int k = 0; k < size; k++)
		{
			gridfile >> grid[k][i];
		}
	}
}