/*
 * Reese Myers
 * CPSC 1070: 010
 * 04/09/2023 */

// Purpose: This file defines all of the functions for the Cipher class.
// The Cipher class creates Cipher objects that can be used to encrypt and 
// decrypt messages using a Vigenère cipher and a specified key.

#include "Cipher.h"
#include <cctype> // for isalpha()

using namespace std;

// The default constructor initializes isCipher to true and keyLength to 4.
// An array of size 4 is dynamically allocated and the address of the array
// is assigned to keyArray. The array is filled with the key {1,2,3,4} using
// a for loop. The queue is then initialized.
Cipher::Cipher() {
	isCipher = true;
	keyLength = 4;

	keyArray = new int[keyLength];
	for (int i = 0; i < keyLength; i++) {
		keyArray[i] = i + 1;
	}

	initializeQueue();
}

// This constructor is used by the CipherAdvanced class. The boolean value is
// used only to differentiate this constructor. In this constructor,
// isCipher is set false.
Cipher::Cipher(bool b) {
	isCipher = false;
}

// The destructor frees the memory of the array pointed to by keyArray if
// isCipher is true. isCipher is true when an object is an instance of the
// base Cipher class.
Cipher::~Cipher() {
	if (isCipher) {
		delete[] keyArray;
		keyArray = nullptr;
	}
}

// This function initializes the queue by enqueuing each int contained in the 
// key array one at a time. keyUsed is set false.
void Cipher::initializeQueue() {
	keyUsed = false;
	for (int i = 0; i < keyLength; i++) {
                keyQueue.enqueue(keyArray[i]);
        }
}

// This function reinitializes the queue by clearing the queue's contents
// and then calling the initializeQueue() function.
void Cipher::reinitializeQueue() {
	keyQueue.clear();
	initializeQueue();
}

// This function sets the cipher to use a new key.
// It takes in an int representing the size of the key and an
// array representing each shift to use in the key.
void Cipher::setCipher(int size, int key[]) {
	// If the queue used for the keys is not empty,
	// the queue is cleared.
	if (!keyQueue.isEmpty()) {
		keyQueue.clear();
	}
	// If keyArray does not point to nullptr, the memory
	// held by the array pointed to by keyArray is freed.
	if (keyArray != nullptr) {
		delete[] keyArray;
		keyArray = nullptr;
	}
	
	keyLength = size; // Assignes the value of size to keyLength
	keyArray = new int[keyLength]; // Dynamically allocates an int array of size keyLength

	int tempShift;

	// This for loop iterates keyLength # of times.
	// On each iteration, tempShift is assigned the value at the ith index in the key array.
	// The remainder of dividing tempshift by 26 is assigned to tempShift in order to 
	// handle excessively large keys or negative shifts.
	// If tempShift is negative after this, keyArray[i] is set to 26 more than tempShift
	// Otherwise, keyArray[i] is set to tempShift.
	// keyArray[i] is then enqueued.
	for (int i = 0; i < keyLength; i++) {
		tempShift = key[i];
		tempShift %= 26;
		if (tempShift < 0) {
			keyArray[i] = tempShift + 26;
		}
		else {
			keyArray[i] = tempShift;
		}
		keyQueue.enqueue(keyArray[i]);
	}
}

// This function returns a pointer to keyArray.
int* Cipher::getCipher() {
	return keyArray;
}

// This function returns the length of the key as an int.
int Cipher::getKeyLength() {
	return keyLength;
}

// This function is used to encode messages using a key.
// It takes in a string representing the message to encode.
// It returns the encoded message.
string Cipher::encodeMessage(string in) {
	string encodeResult = ""; // Initialized encodeResult to a blank string
	int stringSize = in.size(); // sets stringSize to the size of the input string
	
	// If key has already been used, queue is reinitialized.
	if (keyUsed) {
                reinitializeQueue();
        }
	
	// Each alphabetic letter in the in string is added one at a time to encodeResult.
	for (int i = 0; i < stringSize; i++) {
		if (isalpha(in.at(i))) {
			encodeResult += tolower(in.at(i)); 
		}
	}

	stringSize = encodeResult.size(); // sets StringSize to the size of encodeResult

	int currentShift;

	// This for loop iterates stringSize # of times.
	// On each iteration, an int is removed from the front of the queue and added at the end.
	// The value of this int is used to shift the character at encodeResult[i] forward down the alphabet a specific number.
	// If a letter goes past z, it wraps back around to the start of the alphabet.
	for (int i = 0; i < stringSize; i++) {
		keyQueue.dequeue(currentShift);
		keyQueue.enqueue(currentShift);
		encodeResult[i] = (((encodeResult[i] - 97) + currentShift) % 26) + 97;
	}
	keyUsed = true; // keyUsed is set true so that the program knows the queue may need to be reinitialized.

	return encodeResult; // The encoded message is returned.
}

// This function is used to decode messages using a key.
// It takes in a string representing the encoded message.
// It returns the decoded message.
string Cipher::decodeMessage(string in) {
	int currentShift, numCheck, stringSize;
	
	stringSize = in.size(); // sets stringSize to size of input string
	
	// If key has already been used, queue is reinitialized.
	if (keyUsed) {
                reinitializeQueue();
        }
	
	// This for loop iterates stringSize # of times.
	// On each iteration, an int is removed from the front of the queue and added at the end.
	// The value of this int is used to shift the character at in[i] back in the alphabet a specific number.
	// numCheck is calculated by subtracting the ascii value of in[i] by currentShift.
	// If numCheck is less than 97, in[i] is set to 26 more than numCheck.
	// Otherwise, in[i] is set to numCheck.
	for (int i = 0; i < stringSize; i++) {
		keyQueue.dequeue(currentShift);
		keyQueue.enqueue(currentShift);
		numCheck = in[i] - currentShift;
		if (numCheck < 97) {
			in[i] = numCheck + 26;
		}
		else {
			in[i] = numCheck;
		}
	}
	keyUsed = true; // keyUsed is set true so that the program knows the queue may need to be reinitialized

	return in; // The decoded message is returned.
}

