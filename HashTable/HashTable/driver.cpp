#include <iostream>
#include <fstream>
#include <chrono>
#include "HashTable.h"

using namespace std;
using namespace std::chrono;

int main() {

	string userInput;
	string ans = "";
	bool again = true;

	hashTable myHash;

	ifstream inFile;
	string inFileName;

	string line;
	inFile.open("words.txt");


	if (!inFile)
	{
		cout << "file not found" << endl;
		exit(2);
	}
	while (!inFile.eof()) {
		inFile >> line;
		myHash.insertWord(line);
	}
	
	while (again) {
		again = true;
		do {
			cout << "Enter a word to search: ";
			cin >> userInput;

			auto start = high_resolution_clock::now();
			myHash.findWord(userInput);

			auto end = high_resolution_clock::now();
			auto duration = duration_cast<microseconds>(end - start);

			cout << "Time taken to find word: "
				<< duration.count() << " microsecs" << endl;

			cout << "Again? y/n ";
			cin >> ans;
			if (ans != "y")again = false;
		} while (again);

	}
	
}