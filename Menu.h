#ifndef SPLASHSCREEN_H_INCLUDED
#define SPLASHSCREEN_H_INCLUDED

#include <fstream>
#include <string>
#include <iomanip>
#include "SDL_Plotter.h"
#include "Box.h"
#include "HighScores.h"

class showMenu{
    private:
        bool start;
        bool highScore;
    public:
        showMenu();
        showMenu(bool, bool);

        /*
        description: Shows high score before game starts
        return: void
        precondition: High score file exists
        postcondition: High score is shown
        */
        void showHighScores(ostream&);

        /*
        description: Displays menu
        return: void
        precondition: showMenu object is created
        postcondition: Menu is displayed
        */
        void displayMenu(ostream&, bool&);
};

#endif // SPLASHSCREEN_H_INCLUDED
