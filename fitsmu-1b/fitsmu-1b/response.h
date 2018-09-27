// Project 1b
//
// Team: fitsmu
// Justin Fitch
// Sam Smucny
// response.h: Header file defining the Response class
// 
// This class holds the response to a guess:
//  - The number correct
//  - The number incorrect
 

#include <iostream>

class response
{

public:

	response(const int& numberCorrect, const int& numberIncorrect);
	response();

	// Setters
	void setNumCorrect(const int& numberCorrect);
	void setNumIncorrect(const int& numberIncorrect);

	// Getters
	int getNumCorrect() const;
	int getNumIncorrect() const;

private:

	int numberCorrect;
	int numberIncorrect;


};
