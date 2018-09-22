/**
 * cpp that holds funtion implementation of response.h header file
 *
 * TODO: Add other shit
 */

#include "response.h"

response::response(int numberCorrect, int numberIncorrect) {
   this->numberCorrect = numberCorrect;
   this->numberIncorrect = numberIncorrect;
}

void response::setNumCorrect(int numberCorrect) {
   this->numberCorrect = numberCorrect;
}

void response::setNumIncorrect(int numberIncorrect) {
   this->numberIncorrect = numberIncorrect;
}

int response::getNumCorrect() const {
   return this->numberCorrect;
}

int response::getNumIncorrect() const {
   return this->numberIncorrect;
}
