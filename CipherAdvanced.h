/*
 * Reese Myers
 * CPSC 1070: 010
 * 04/09/2023 */

// Purpose: This file declares all of the functions for the CipherAdvanced class.
// The CipherAdvanced class is used to decrypt messages that have been encrypted
// with Vigenère ciphers of length 1-5. The class is able to generate all the possible
// plaintexts of a ciphertext message by generating all possible keys and comparing
// all mesaages encrypted with these keys to a dictionary file.

#ifndef CIPHERADVANCED_H
#define CIPHERADVANCED_H
#include "Cipher.h"

class CipherAdvanced : private Cipher {
	public:
		CipherAdvanced();
		~CipherAdvanced();
		void unknownScramble(string word);

};
#endif
