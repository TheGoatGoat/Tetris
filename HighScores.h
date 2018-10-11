#ifndef HIGHSCORE_H_INCLUDED
#define HIGHSCORE_H_INCLUDED
#include "Box.h"

#include <string>
#include <ostream>

using namespace std;

class HighScores
{
  private:
      unsigned long long int score;
      string name;

  public:
      /*
      description: Default constructor
      return: n/a
      precondition: valid object is  initialized
      postcondition: object is created with default settings
      */
      HighScores();

      /*
      description: sets the name variable
      return: void
      precondition: valid object is  initialized
      postcondition: name variable is changed to the string passed
      */
      void setName( string );

      /*
      description: sets the score
      return: void
      precondition: valid object is  initialized
      postcondition: object is created with default settings
      */
      void setScore(unsigned long long int);

      /*
      description: retrieves the score
      return: Unsigned long long int
      precondition: valid object is  initialized
      postcondition: returns the score
      */
      unsigned long long int getScore() const;

      /*
      description: retrieves the name
      return: string
      precondition: valid object is  initialized
      postcondition: returns the name
      */
      string getName() const;
};

#endif // HIGHSCORE_H_INCLUDED

