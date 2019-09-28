#include "secureWord.h"
#include <iostream>
#include <string>

using namespace std;




void secureWord::encryptWord(char input[100], int inputKey, bool flag) {


	size = strlen(input); // Set the size equal to the length of the character array we have just imported
	key = inputKey; // The encrypt key will also be set from the import

	if (flag != true) { // If the word is not encrypted
		for (int i = 0; i < size; i++) {
			word[i] = (((input[i] - 97) + inputKey) % 26) + 97; //we want encrypt and store in our char word[100] array from our class
			// This is the basic Ceasar Cypher in action, we use 97 because this is where 'a' starts in the ASCII table
		}
	}
	else {
		// Just store
		for (int i = 0; i < size; i++) {
			word[i] = input[i];
		}
	}
	
	// Terminate the character array
	word[size] = '\0';

	encrypted = true;
}
void secureWord::displaySafeWord(secureWord safeword) {

	cout << "Safe Word:    " << safeword.word << endl;
	cout << "Size:         " << safeword.size << endl;
	cout << "Encrypted:    " << (safeword.encrypted ? "true " : "false ") << endl;
	cout << "Key:          " << safeword.key << endl;
	cout << endl;

}
bool secureWord::compare(char data[100])
{  
	// The first thing to do in this function is to encrypt the users word
	int result; // To store the bool return of strcmp()
	char tempEncryptedWord[100];

	for (int i = 0; i < size; i++) {

		tempEncryptedWord[i] = (((data[i] - 97) + key) % 26) + 97; //we want encrypt and store in our char word[100] array from our class

	}
	tempEncryptedWord[size] = NULL;
	result = strcmp(tempEncryptedWord, word);

	return  (result == 0 ? true : false);
}


