/**
 * This header file holds all of the data members and function declarations
 *  for the mastermind class.
 * This class handles the playing of the game, holding a code object
 *
 * TODO: Add other shit
 */

#include "response.h"

class mastermind {

public:

   // Constructors
   mastermind(int codeLen, int maxDig);
   mastermind();

   // Prints the secret code
   void printCode() const;

   // Reads a guess from the keyboard and returns a code object that represents
   // the guess
   code humanGuess();

   // Passed a code object and returns a response (how many correct, how many
   // incorrect)
   response getResponse(code userCode);

   // Passed a response and returns true if the response indicates that the
   //  board has been solved
   bool isSolved(response userResponse);

   // Initializes random code, prints it to screen, and iteratively takes a
   //  guess from the user and prints the response until either the codemaker
   //  or codebreaker has won
   void playGame();

private:

   // Private data members
   code secretCode;
}
