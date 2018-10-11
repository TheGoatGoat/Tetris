#ifndef SPAWN_H_INCLUDED
#define SPAWN_H_INCLUDED

#include <cstdlib>
#include <time.h>

#include "Box.h"


// Block Coordinate Matrix
static int block_coordinates[7][8] =
{
     //O - Block
     {0, 4, 0, 5, 1, 4, 1, 5},
     //I - Block
     {0, 3, 0, 4, 0, 5, 0, 6},
     //T - Block
     {0, 4, 1, 3, 1, 4, 1, 5},
     //S - Block
     {1, 3, 1, 4, 0, 4, 0, 5},
     //Z - Block
     {0, 3, 0, 4, 1, 4, 1, 5},
     //J - Block
     {0, 3, 1, 3, 1, 4, 1, 5},
     //L - Block
     {1, 3, 1, 4, 1, 5, 0, 5}
};

// Spawn Class
class Spawn
{
    private:
        //0 to 6
        int shape;
        Box block[4];

    public:
        //Spawns new block randomly and assign attributes
        Spawn();


        /*
        description: Moves the Spawn Block to the right
        return: nothing
        precondition: Spawn Block is already generated
        postcondition: Allows movement to the right
        */
        void moveRight();

        /*
        description: Moves the Spawn Block to the Left
        return: nothing
        precondition: Spawn Block is already generated
        postcondition: Allows movement to the Left
        */
        void moveLeft();

        /*
        description: Moves the Spawn Block down
        return: nothing
        precondition: Spawn Block is already generated
        postcondition: Allows movement downward
        */
        void fall();

        /*
        description: Sets the box
        return: nothing
        precondition: Coordinates set in place
        postcondition: Sets the new box
        */
        void setBox(Box&, int);


        /*
        description: Gets a box
        return: Box
        precondition: Box already set
        postcondition: Grabs the box
        */
        Box getBox(int);

        /*
        description: Rotates the block counter-clockwise
        return: Spawn
        precondition: Spawn block is already generated
        postcondition: Block is in new orientation
        */
        Spawn rotateBlock();
};

#endif // SPAWN_H_INCLUDED
