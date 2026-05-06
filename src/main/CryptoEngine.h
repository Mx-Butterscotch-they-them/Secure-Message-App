/*
* Author: Alex Lancaster
* What I go by: Anything but she/her, he/him, it/its, and just solely my name
* Date last updated: 4/10/2026
* Purpose:
* A component of the overall hybrid cryptography system that is responsible for encrypting and decrypting messages using AES-256 encryption. 
* This class will take care of: 
* Key generation
* Encryption processes
* Decryption processes
* Error handling related to cryptographic operations
*/

#ifndef ENCRYPTIONPROJECT_SOURCE_FILES_CRYPTOENGINE_H
#define ENCRYPTIONPROJECT_SOURCE_FILES_CRYPTOENGINE_H

#include <string>
#include <openssl/aes.h>
#include <openssl/err.h>
#include <openssl/rand.h>

class CryptoEngine {
private:
	AES_KEY aesKey;
	unsigned char iv[256];
	unsigned char key[32];




public:
	//constructor
	CryptoEngine() {
		if (!RAND_bytes(key, sizeof(key))) {
			catchError();
		}

		if (!RAND_bytes(iv, sizeof(iv))) {
			catchError();
		}
	}

	void decryptMessage();
	void encryptMessage();
	void catchError() {
		ERR_print_errors_fp(stderr);
		abort();
	}
	
};

#endif