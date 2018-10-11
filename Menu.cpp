#include "Menu.h"
#include "Spawn.h"
#include "Box.h"



showMenu::showMenu(){
    start = false;
    highScore = false;
}

showMenu::showMenu(bool s, bool h){
    start = s;
    highScore = h;
}


void showMenu::showHighScores(ostream& out){
    HighScores score[5];

    ifstream inFile;
    inFile.open("HighScore.txt");

    string nameFromFile;
    int scoreFromFile;

    inFile.ignore(100 , '\n');
    inFile.ignore(100, '\n' );

    for( int i = 0; i < 5; i++ )
    {
        inFile >> nameFromFile >> scoreFromFile;

        score[i].setName( nameFromFile);
        score[i].setScore( scoreFromFile);
    }

    inFile.close();

    out << "\t===HIGHSCORES===\n";
    out << "Name\t\t\t\tScore\n";

    for(int i = 0; i < 5; i++)
    {
        out << setw(30) << left;
        out << score[i].getName() << "\t" <<  score[i].getScore() << "\n";
    }

}

//cout in the console, doesn't play game until user presses '1' in the console, not the game
void showMenu::displayMenu(ostream& out, bool& started){
    char key;

    while(!started){
        out << endl << "Press 1 to Start" << endl;
        out << "Press 2 to see HighScores" << endl;

        cin >> key;

        switch(key){
            case '1':   started = true;
                        break;
            case '2':   showHighScores(out);
                        break;
        }
    }

}
