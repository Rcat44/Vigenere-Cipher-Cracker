/*
 * Reese Myers
 * CPSC 1070: 010
 * 04/09/2023 */

// Purpose: This program is designed to encrypt and decrypt messages using a Vigenère cipher given both
// a message and a key. The program can also decrypt messages without knowing the key (if the key length is 1-5)
// by comparing all possible combinations to a dictionary file. 
// This file serves as a driver to test functionality.

#include "Cipher.h"
#include "CipherAdvanced.h"
#include <iostream>
#include <string>

using namespace std;

void runCiphers();
void printKey(const int*, int);

// The main function only calls runCiphers().
int main(void) {
	runCiphers();	
	return 0;
}

// This function tests much of the functionality of the program. It declares a Cipher object
// to encrypt and decrypt with a key. It then creates a CipherAdvanced object to decrypt without a key.
void runCiphers() {
	Cipher c1;
	
	// After calling the default constructor, c1.getCipher() should return a pointer to an array that
	// contains {1,2,3,4}. c1.getKeyLength() should return 4.
        const int *displayKeys = c1.getCipher();
        int keyLength = c1.getKeyLength();
	
	// The key being used is printed. The message "Secret Message" is encrypted using
	// the displayed key. The encrypted message is then printed out
        printKey(displayKeys, keyLength);
        string encoded = "Secret Message!";
        cout << "Encoding: " << encoded << endl;
        encoded = c1.encodeMessage(encoded);
        cout << "Encoded: " << encoded << endl << endl;

        // The key is printed once again. The result of decoding the message with the displayed
	// key is printed out.
	printKey(displayKeys, keyLength);
        cout << "Decoding: " << encoded << endl;
        string decoded = c1.decodeMessage(encoded);
        cout << "Decoded: " << decoded << endl << endl;
	
	// Creates a CipherAdvanced object to test if functionality to decrypt without a key is working properly.
	// a1.unknownScramble is called. All the decryption possibilities for the string passed as an argument
	// should be displayed.
	CipherAdvanced a1;
	// a1.unknownScramble("xhakfzv");
}

// This function is used to print the key used to encrypt or decrypt a message.
// It takes in a pointer to a constant int (points to the first element of a keys array)
// and a int representing the length of the key being used.
void printKey(const int *displayKeys, int keyLength) {
        int i; // This int will be used for accessing specific indices before and after the for loop

	keyLength--; // Decrements keyLength so that the for loop will iterate 1 less time.

	cout << "Key: [";

	// The for loop prints every number of the key used except the last.
	// In the case that the length of the key used is only 1, prints nothing.
        for (i = 0; i < keyLength; i++) {
               cout << displayKeys[i] << ", ";
        }
        cout << displayKeys[i] << "]\n"; // Prints the last number used in the key.
}
