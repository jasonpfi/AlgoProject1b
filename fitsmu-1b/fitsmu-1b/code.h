// Project 1b
//
// Team: fitsmu
// Jason Fitch
// Sam Smucny
//
// code.h: header file for code class and codeGuess

#pragma once
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <time.h>
#include "response.h"

class code
	// Main class defining a code, secret or user input
	// A code is defined by its length and the value of
	// the maximum digit, as well as a vector defining the code
{
public:

	// Constructors
	code();
	code(const int& codeLen, const int& maxDig);
	code(const std::vector<int>& secret, const int& maxDigit);

	// Non-Static Member Functions
	void printCode() const;
	void generateSecretCode();
	int checkCorrect(const code& guess) const;
	int checkIncorrect(const code& guess) const;
	bool checkValidity() const;
	bool checkWin(const response& userResponse) const;
	code generateUserCode() const;

private:

	// Fields
	int codeLen;
	int maxDig;
	std::vector<int> secret;

	// Private Method
	void checkCorrectForIncorrect(std::vector<int>& checkedDigits,
		const code& guess) const;

	// Static Member Functions
	static bool find(const std::vector<int>& v, const int& digit);
}; // End of Code class Declaration
