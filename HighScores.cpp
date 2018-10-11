#include "HighScores.h"

HighScores::HighScores()
{
    score = 0;
    name = "empty";
}

void HighScores::setName( string user )
{
    name = user;
}

void HighScores::setScore(unsigned long long int record)
{
    score = record;
}

unsigned long long int HighScores::getScore() const
{
    return score;
}

string HighScores::getName() const
{
    return name;
}

