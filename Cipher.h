/*
 * Reese Myers
 * CPSC 1070: 010
 * 04/09/2023 */

// Purpose: This file declares all of the functions and member variables for the Cipher class.
// The Cipher class creates Cipher objects that can be used to encrypt and
// decrypt messages using a Vigenère cipher and a specified key.

#ifndef CIPHER_H
#define CIPHER_H
#include "Queue.h"
#include <string>

using namespace std;

class Cipher {
	private:
		bool isCipher;
		int keyLength;
		int *keyArray;
		bool keyUsed;
		Queue keyQueue;
		void initializeQueue();
		void reinitializeQueue();
	public:
		Cipher();
		Cipher(bool);
		~Cipher();

		void setCipher(int, int[]);
		int* getCipher();
		int getKeyLength();

		string encodeMessage(string in);
		string decodeMessage(string in);
};
#endif
