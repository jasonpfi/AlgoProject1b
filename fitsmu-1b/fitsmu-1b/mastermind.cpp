/**
 * This cpp file holds all of the data members and function declarations for
 *  the mastermind class.
 * This class handles playing the game and determining which user has won
 */

#include <iostream>
#include <string>
#include "mastermind.h"

std::ostream& operator << (std::ostream& os, response& response1)
// Overloaded output operator
{
	return os
		<< "Number Correct: " + std::to_string(response1.getNumCorrect())
      << std::endl
      << "Number Incorrect: " + std::to_string(response1.getNumIncorrect())
      << std::endl;
}

bool operator== (const response& lhs, const response& rhs)
// Overloaded equality operator
{
	return lhs.getNumCorrect() == rhs.getNumCorrect()
		&& lhs.getNumIncorrect() == rhs.getNumIncorrect();
}

mastermind::mastermind(int codeLen, int maxDig)
// Constructor with passed parameters
{
	this->secretCode = code(codeLen, maxDig);
}

mastermind::mastermind()
// Constructor with default values
{
	this->secretCode = code(5, 10);
}

void mastermind::printCode() const
// Prints secret code (for debugging)
{
	this->secretCode.printCode();
}

code mastermind::humanGuess()
// Reads a guess from the keyboard and returns a code object that represents
// the guess
{
	return this->secretCode.generateUserCode();
}

response mastermind::getResponse(code& userCode)
// Passed a code object and returns a response (how many correct, how many
// incorrect)
{
	response guessResponse;
	guessResponse.setNumCorrect(secretCode.checkCorrect(userCode));
	guessResponse.setNumIncorrect(secretCode.checkIncorrect(userCode));

	return guessResponse;
}

bool mastermind::isSolved(const response& userResponse)
// Passed a response and returns true if the response indicates that the
//  board has been solved
{
	return secretCode.checkWin(userResponse);
}

mastermind mastermind::acceptInput()
// Helper function to read input from keyboard
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
		std::cout << "One or both of the values you entered were not valid."
			"Please choose two non negative integers." << std::endl;
		return acceptInput();
	}
	else
	{
		return mastermind(codeLength, maxDigit);
	}
}

void mastermind::playGame()
// Initializes random code, prints it to screen, and iteratively takes a
// guess from the user and prints the response until either the codemaker
// or codebreaker has won
{
	std::cout << "Welcome to MASTERMIND!";
	std::cout << "Can you guess the secret code in 10 guesses?" << std::endl;

	code userCode;
	response userResponse;

	this->printCode();

	for (int i = 0; i < 10; i++)
	{
		userCode = this->humanGuess();
		if (!userCode.checkValidity())
		{
			std::cout << "Hmm... One of your digits was too high, try again";
			userCode = this->humanGuess();
		}

		userResponse = this->getResponse(userCode);

		if (this->isSolved(userResponse))
		{
			std::cout << "You guessed the code!";
			return;
		}

		std::cout << userResponse;
	}

	std::cout << "Sorry, you lose! The secret code was: ";
	this->printCode();
}







