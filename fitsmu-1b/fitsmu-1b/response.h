/**
 * Header file defining the Response class
 * This class holds the response to a guess:
 *  - The number correct
 *  - The number incorrect
 *
 *  TODO: add other shit
 */

class response
{

public:

	response(int numberCorrect, int numberIncorrect);
	response()
	{
		this->numberCorrect = 0;
		this->numberIncorrect = 0;
	}

	// Setters
	void setNumCorrect(int numberCorrect);
	void setNumIncorrect(int numberIncorrect);

	// Getters
	int getNumCorrect() const;
	int getNumIncorrect() const;

private:

	int numberCorrect;
	int numberIncorrect;


};
