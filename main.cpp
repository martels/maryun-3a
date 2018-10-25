#include "main.h"
#include "dictionary.h"
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	Grid block;
	Dictionary dictionary;
	ofstream file;
	file.open("result.txt");
	dictionary.sort();

	file << dictionary << "\n";
	file.close();
	// cout << block << endl << endl;
	// cout << dictionary << endl << endl;
}
