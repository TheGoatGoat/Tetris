#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <iostream>
#include <time.h>
#include <iomanip>
#include <fstream>
#include <cstdlib>

#include "SDL_Plotter.h"
#include "Point.h"
#include "Line.h"
#include "Box.h"
#include "Spawn.h"
#include "HighScores.h"

using namespace std;

/**
description: Operates the game
return: nothing
precondition: Game is started
postcondition: Game is played
**/
void playGame(unsigned long long int& currentScore);

/**
description: Displays splash page
return: nothing
precondition: Game is started
postcondition: Splash page is displayed
**/
void displaySplash();

/**
description: Displays high score after the game
return: nothing
precondition: Game ended
postcondition: High score is displayed
**/
void displayHighScore(unsigned long long int& currentScore, string name);


/**
description: Draws the bocks on the SDL
return: nothing
precondition: Proper coordinates set in place
postcondition: Draws the block
**/
void drawBlock(Spawn shape, Box board[20][10], SDL_Plotter& g);

/**
description: deactivates the bocks on the SDL
return: nothing
precondition: Proper coordinates set in place
postcondition: Erases block
**/
void eraseBlock(Spawn shape, Box board[20][10], SDL_Plotter& g);

/**
description: removes the control once bottom collision
return: nothing
precondition: Spawn piece touching bottom
postcondition: Stops controlling spawn piece
**/
void removeControl(Spawn shape, Box board[20][10]);

/**
description: Check for bottom collision
return: integer
precondition: Spawn piece is already generated
postcondition: returns 1
**/
int check_bot_collision(Spawn shape, Box board[20][10]);

/**
description: Check for left boundary and another active block
return: int
precondition: Spawn piece is already generated
postcondition: Stops moving current block left returns 2
**/
int check_left_collision(Spawn shape, Box board[20][10]);

/**
description: Check for right boundary and another active block
return: int
precondition: Spawn piece is already generated
postcondition: Stops moving current block left and return 3
**/
int check_right_collision(Spawn shape, Box board[20][10]);

/**
description: Check to see if row is complete. If true it deactivates the box.
return: nothing
precondition: Block are generating to fill rows
postcondition: deactivates the row if row is complete
**/
void lineDetection(Box board[20][10], SDL_Plotter& g);

/**
description: Sort the high score results
return: nothing
precondition: Scores set in place
postcondition: Rearranges the names and scores
**/
void sortScores( HighScores score[] );


/**
description: Check to see if rotation is possible
return: bool
precondition: Spawn piece is already generated
postcondition: returns true or false depending if rotation is possible
**/
bool allowRotation(Spawn shape, Box board[20][10]);

/**
description: Check to see if an active block (that is not spawn block) reaches certain hight
return: bool
precondition: Blocks already generated
postcondition: returns bool true if active block reaches the top
**/
bool topDetection(Box board[20][10], SDL_Plotter& g);

#endif // GAME_H_INCLUDED
