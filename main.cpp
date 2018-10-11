#include <iostream>
#include <time.h>
#include <iomanip>
#include <fstream>

#include "SDL_Plotter.h"
#include "Point.h"
#include "Line.h"
#include "Box.h"
#include "Spawn.h"
#include "HighScores.h"
#include "Game.h"
#include "Menu.h"

using namespace std;

int COL = 300;
int ROW = 600;

unsigned long long int currentScore = 0;
int main(int argc, char** argv)
{
    bool started = false;
    char keyInput;
    showMenu menu;
    //Prompt user to start game
    cout << "Welcome to TETRIS." << endl;

    menu.displayMenu(cout, started);

    string name;
    if(started){
        cout << "Enter your name:" << endl;
        cin >> name;
        displaySplash();

        //Create SDL Plotter
        playGame(currentScore);
        started = false;
    }

    displayHighScore(currentScore, name);

    cout << endl << "Enter e to exit" << endl;
    cin >> keyInput;

    if(keyInput == 'e'){
        return 0;
    }
}


