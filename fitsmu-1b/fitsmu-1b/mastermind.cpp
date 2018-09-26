/**
 * This cpp file holds all of the data members and function declarations for
 *  the mastermind class.
 * This class handles playing the game and determining which user has won
 *
 * TODO: add other shit
 */

#include <iostream>
#include <string>
#include "mastermind.h"

 // This is not working now, wait for class
std::ostream& operator << (std::ostream& os, response& response1)
{
	return os << "Number Correct: " + std::to_string(response1.getNumCorrect()) +
		", Number Incorrect: " + std::to_string(response1.getNumIncorrect()) +
		"\n";
}

mastermind::mastermind(int codeLen, int maxDig)
{
	this->secretCode = code(codeLen, maxDig);
}

mastermind::mastermind()
{
	this->secretCode = code(5, 10);
}

void mastermind::printCode() const
{
	this->secretCode.printCode();
}

code mastermind::humanGuess()
{
	return this->secretCode.generateUserCode();
}

response mastermind::getResponse(code& userCode)
{
	response guessResponse;
	guessResponse.setNumCorrect(secretCode.checkCorrect(userCode));
	guessResponse.setNumIncorrect(secretCode.checkIncorrect(userCode));

	return guessResponse;
}

bool mastermind::isSolved(const response& userResponse)
{
	return secretCode.checkWin(userResponse);
}

mastermind mastermind::acceptInput()
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







