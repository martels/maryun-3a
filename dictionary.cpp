#include "dictionary.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

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
	int i, j, first;
	string temp;
	int length = dictionary.size();
	double percent = 0;

	for(i = length - 1; i > 0; i--)
	{
		first = 0;
		for(j = 1; j <= i; j++)
		{
			if(dictionary[j] < dictionary[first])
			{
				first = j;
			}
		}
		temp = dictionary[first];
		dictionary[first] = dictionary[i];
		dictionary[i] = temp;
		if(first%10)
		{
		percent = (first/length)*100;
		cout << "Sorting(" << percent << "%) \r";
		}
	}
	cout << endl;
	return;


// 	string lowest, temp;
// 	int min;
// 	int i = dictionary.size();
// 	int start = 0; 
// 	while(start != i)
// 	{
// 		lowest = dictionary.at(start);
// 		for(int k = start; k < i; k++)
// 		{
// 			if(dictionary.at(k) < lowest)
// 			{
// 				lowest = dictionary.at(k);
// 				min = k;
// 			}
// 		temp = dictionary.at(start);
// 		dictionary.at(start) = lowest;
// 		dictionary.at(min) = temp;
// 		start ++;
// 		}

// 		if(start%100 == 0)
// 		{
// 			cout << "Sorting(" << start << "/" << i << ") \r";
// 		}
// 	}
// 	cout << endl << endl;
}

int Dictionary::search(string key)
{
	int first = 0;
	int last = dictionary.size() - 1;
	int mid = 0;
	while(first <= last)
	{
		mid = (first + last) / 2;
		if(key > dictionary.at(mid))
		{
			first = mid + 1;
		}
		else if(key < dictionary.at(mid))
		{
			last = mid - 1;
		}
		else 
		{
			return mid;
		}
	}
	return -1;
}

Grid::Grid()
{
	string file;
	int count = 0;
	int atte = 5;
	int size;
	cout << "Which file would you like to open?" << endl;
	getline(cin, file);
	while(count < atte) {
	if(file == "input15.txt") {
		size = 15;
		break;
	}
	else if(file == "input30.txt") {
		size = 30;
		break;
	}
	else if(file == "input50.txt") {
		size = 50;
		break;
	}
	else {
		cout << "File could not be openned by this program " << atte - count << " attempts remaining." << endl;
		count++;
	} }

	if(count == atte)
	{
		cout << "You are entering the wrong file names. Exiting program.";
		return;
	}
	vector<vector<int>> temp(size);
	for(int i = 0; i < size ; i++)
	{
		temp[i].resize(size);
	}
	ifstream gridfile;
	gridfile.open(file);

	if(gridfile.fail())
	{
		cerr << "Error opening file" << endl;
		exit(1);
	}
	for(int i = 0; i < size; i++)
	{
		for(int k = 0; k < size; k++)
		{
			gridfile >> temp[k][i];
		}
	}
	grid = temp;
	gridfile.close();
}

ostream& operator<< (ostream& ostr, const Dictionary& rhs)
{
	int size = rhs.dictionary.size();
	for(int i = 0; i < size; i++)
	{
		ostr << rhs.dictionary.at(i) << endl;
	}
	return ostr;
}

ostream& operator<< (ostream& ostr, const Grid& rhs)
{
	int size = rhs.grid.size();
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
