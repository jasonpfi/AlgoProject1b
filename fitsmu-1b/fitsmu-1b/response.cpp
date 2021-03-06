// Project 1b
//
// Team: fitsmu
// Jason Fitch
// Sam Smucny
//
// source file for response class

#include "response.h"

response::response(const int& numberCorrect, const int& numberIncorrect)
// Constructs a response object and initializes private data members
{
	this->numberCorrect = numberCorrect;
	this->numberIncorrect = numberIncorrect;
}

response::response()
// Default constructor
{
	this->numberCorrect = 0;
	this->numberIncorrect = 0;
}

void response::setNumCorrect(const int& numberCorrect)
// Sets value of numberCorrect
{
	this->numberCorrect = numberCorrect;
}

void response::setNumIncorrect(const int& numberIncorrect)
// Sets value of numberIncorrect
{
	this->numberIncorrect = numberIncorrect;
}

int response::getNumCorrect() const
// Gets value of numberCorrect
{
	return this->numberCorrect;
}

int response::getNumIncorrect() const
// Gets value of numberIncorrect
{
	return this->numberIncorrect;
}
