#include "secureWord.h"
#include <iostream>
#include <fstream>
using namespace std;


int main() {

	char word[100];
	bool flag;
	int key;

	/* // Create an array of objects that will give us access to all
	the member variables and functions of the 'secureWord' Class*/
	secureWord wordList[8];

	ifstream theFile("input.txt");
	// Initialise memory used by secureWord C++14 complains if we don't
	
	for (size_t i = 0; i < 8; i++)
	{
		wordList[i].word[0] =  '\0';
	}
	
	int count = 0;
	if (theFile.is_open()) {// Process 'word', 'flag' and 'key' into the variables, this will populate the wordList array with the textfile data 
		while (theFile >> word >> flag >> key) {

			//cout << "Original textfile word" << word << endl;
			wordList[count++].encryptWord(word, key, flag); // Send the new wordList values to the 'encryptWord' function
			wordList->displaySafeWord(wordList[count - 1]);

		}
		theFile.close();
	}

	else {
		cout << " File can not be opened!\n";
	}
	char userdata[100];
	bool found;
	// Ask for user input, encrypt it before then comparing it to all the words we have just encrypted and stored in our object
	cout << "Enter word to see if we have a securely encrypted version of it: ";
	cin >> userdata;

	bool result = wordList[8].compare(userdata);

	if (result == 0)// If they are identical, the strcmp() function will return a zero
	{
		cout << "Found Word";

	}
	else {
		cout << "Not Found";
	}

	return 0;
}