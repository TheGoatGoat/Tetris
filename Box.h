#ifndef BOX_H_INCLUDED
#define BOX_H_INCLUDED

#include "Point.h"
#include "Color.h"
#include "SDL_Plotter.h"

class Box{
    private:
        bool activated;
        bool isSpawn;
        int row, col;
        Point p1, p2;
        Color c;

    public:
        Box(int rowNum = 0, int colNum = 0, Color myColor = Color(0,0,0));

        /*
        description: Sets the row coordinate
        return: nothing
        precondition: Points set already
        postcondition: New row for the block
        */
        void setRow(int newRow);

        /*
        description: Sets the column coordinate
        return: nothing
        precondition: Points set already
        postcondition: New column for the block
        */
        void setCol(int newCol);

        /*
        description: Activates the box
        return: nothing
        precondition: Box already initialized
        postcondition: activated to true
        */
        void activate();

        /*
        description: Sets activated and isSpawn to false
        return: nothing
        precondition: Box already initialized
        postcondition: Sets box to black and deactive
        */
        void deactivate();

        /*
        description: Sets color to box
        return: nothing
        precondition: Box already initialized
        postcondition: Set the Box to a new color
        */
        void setColor(Color newColor);

        /*
        description: Set box stasis as spawn block
        return: nothing
        precondition: Box already initialized
        postcondition: sets isSpawn to true
        */
        void setSpawn();

        /*
        description: Set box stasis as not spawn block
        return: nothing
        precondition: Box already initialized
        postcondition: sets isSpawn to false
        */
        void notSpawn();

                /*
        description: returns activated
        return: nothing
        precondition: Box already initialized
        postcondition: returns activated
        */
        bool checkActivation();

        /*
        description: returns isSpawn
        return: nothing
        precondition: Box already initialized
        postcondition: returns isSpawn
        */
        bool checkSpawn();

        /*
        description: Get the row
        return: int
        precondition: Box already initialized
        postcondition: returns the row
        */
        int getRow();

        /*
        description: Get the column
        return: int
        precondition: Box already initialized
        postcondition: returns the column
        */
        int getCol();

        /*
        description: Draw on the SDL_Plotter
        return: nothing
        precondition: Box already initialized
        postcondition: Draws on th SDL_Plotter
        */
        void draw(SDL_Plotter&);
};


#endif // BOX_H_INCLUDED
