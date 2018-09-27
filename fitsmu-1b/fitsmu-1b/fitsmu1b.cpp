// Project 1b
//
// Team: fitsmu
// Justin Fitch
// Sam Smucny
//
// fitsmu1b.cpp : Defines the entry point for the console application.
// This is the Mastermind game
// The Codemaker will create a secret code based on the input from the
// code breaker
//
// The Codebreaker must enter 2 digits:
//  - One defining the code length
//  - Another defining the range of digits
// The Codebreaker will then have 10 guesses to enter the secret code
// After each guess the Codemaker will output 2 digits
//  - One telling how many digits were in the correct place
//  - Another telling how many correct digits were in the wrong place

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <time.h>
#include "mastermind.h"

//bool operator == (const response& response1, const response& response2) {
//   return response1.getNumCorrect() == response2.getNumCorrect() &&
//          response2.getNumIncorrect() == response2.getNumIncorrect();
//}

// Main function, entry point for application
int main()
{
	// Welcome message
	std::cout << "Welcome to MASTERMIND!" << std::endl;
	std::cout << "Can you guess the secret code in 10 guesses?" << std::endl;

	// Seed the random funtion with the time of execution
	srand(time(NULL));

	// Call factory function to initialize mastermind object
	mastermind gameObject = mastermind::acceptInput();

	// Run game
	gameObject.playGame();

	// Wait for user input to end program
	std::cin.get();
}
