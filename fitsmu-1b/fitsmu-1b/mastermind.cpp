// Project 1b
//
// Team: fitsmu
// Jason Fitch
// Sam Smucny
//
// mastermind.cpp: This cpp file holds all of the data members
// and function declarations for the mastermind class.
// This class handles playing the game and determining which user has won

#include <iostream>
#include <string>
#include "mastermind.h"

std::ostream& operator << (std::ostream& os, response& response1)
// Overloaded output operator to print a response
{
	return os
	  << "Number Correct:   " + std::to_string(response1.getNumCorrect())
      << std::endl
      << "Number Incorrect: " + std::to_string(response1.getNumIncorrect())
      << std::endl;
}

bool operator== (const response& lhs, const response& rhs)
// Overloaded equality operator to check if response objects are equal
{
	return lhs.getNumCorrect() == rhs.getNumCorrect()
		&& lhs.getNumIncorrect() == rhs.getNumIncorrect();
}

mastermind::mastermind(int codeLen, int maxDig)
// Constructor with passed parameters of secret code length and max digit
{
	this->secretCode = code(codeLen, maxDig);
}

mastermind::mastermind()
// Constructor with default values for code object
{
	this->secretCode = code(5, 10);
}

void mastermind::printCode() const
// Prints secret code. Calls the code member function to access private data
//  members
{
	this->secretCode.printCode();
}

code mastermind::humanGuess() const
// Reads a guess from the keyboard and returns a code object that represents
//  the guess. Calls the code member function to access private data members
//  of the secret code object
{
	return this->secretCode.generateUserCode();
}

response mastermind::getResponse(const code& userCode) const
// Passed a code object and returns a response (how many correct, how many
//  incorrect). Utilizes the code member functions that contain logic
{
	response guessResponse;
	guessResponse.setNumCorrect(secretCode.checkCorrect(userCode));
	guessResponse.setNumIncorrect(secretCode.checkIncorrect(userCode));

	return guessResponse;
}

bool mastermind::isSolved(const response& userResponse) const
// Passed a response and returns true if the response indicates that the
//  board has been solved. Utilizes code member function to access private
//  data members
{
	return secretCode.checkWin(userResponse);
}

mastermind mastermind::acceptInput()
// Factory function to create mastermind object using user input
{

	int codeLength;
	int maxDigit;

	// Get user input
	std::cout << "Please enter the desired length of the secret code: ";
	std::cin >> codeLength;
	std::cout << "Please enter the maximum digit you want to be in the"
		"secret code: ";
	std::cin >> maxDigit;

	// check negative input
	if (codeLength <= 0 || maxDigit <= 0)
	{
		std::cout << "One or both of the values you entered were not valid. "
			<< "Please choose two non negative integers.\n";

      // Run the function again to get better input
      acceptInput();
	}

   return mastermind(codeLength, maxDigit);
} // End acceptInput()

void mastermind::playGame()
// Initializes random code, prints it to screen, and iteratively takes a
// guess from the user and prints the response until either the codemaker
// or codebreaker has won
{
	code userCode;
	response userResponse;

   // Generate random secretCode
   this->secretCode.generateSecretCode();

	// Print out secret code for debugging
	std::cout << "The secret code: ";
	this->printCode();

	// Game loop that runs at most 10 times
	for (int i = 0; i < 10; i++)
	{
		std::cout << "Attempt #" << (i + 1) << " out of 10" << std::endl;
		userCode = this->humanGuess();

      // Check valid user input (BONUS)
      while (!userCode.checkValidity())
		{
			std::cout << "Hmm... One of your digits was either too "
				<< "high or too low, try again" << std::endl;
			userCode = this->humanGuess();
		}

      // Check correct and check incorrect
		userResponse = this->getResponse(userCode);

      // Check if the game has been won
		if (this->isSolved(userResponse))
		{
			std::cout << "You guessed the code! You win!" << std::endl;
			return;
		}

		std::cout << userResponse;
	} // end game for loop

	std::cout << "Sorry, you lose! The secret code was: ";
	this->printCode();

} // End playGame()







