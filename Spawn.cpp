#include "Spawn.h"

/* Check the shapes and orientation here:
http://tetris.wikia.com/wiki/Tetromino
http://tetris.wikia.com/wiki/Orientation
https://www.youtube.com/watch?v=Atlr5vvdchY
 */


Spawn::Spawn()
{
    shape = rand() % 7;
    int color1, color2, color3;

    do
    {
        color1 =  rand() % 255;
        color2 =  rand() % 255;
        color3 =  rand() % 255;

    }while(color1 != 0 && color2 != 0 && color3 != 0);

    Color newColor = Color(color1,color2,color3);
    //cout << shape << endl;

    for(int i = 0; i < 4; i++)
    {
        block[i].setRow(block_coordinates[shape][i*2]);
        block[i].setCol(block_coordinates[shape][i*2+1]);
        block[i].setColor(newColor);
        block[i].activate();
        block[i].setSpawn();
    }
}


void Spawn::moveRight()
{
    int color1, color2, color3;

    do
    {
        color1 =  rand() % 255;
        color2 =  rand() % 255;
        color3 =  rand() % 255;

    }while(color1 < 65 && color2 < 65 && color3 < 65);

    Color newColor = Color(color1,color2,color3);

    for(int i = 0; i < 4; i++)
    {
        block[i].setCol(block[i].getCol()+1);
        block[i].setColor(newColor);
    }
}

void Spawn::moveLeft()
{
    int color1, color2, color3;

    do
    {
        color1 =  rand() % 255;
        color2 =  rand() % 255;
        color3 =  rand() % 255;

    }while(color1 < 65 && color2 < 65 && color3 < 65);


    Color newColor = Color(color1,color2,color3);
    for(int i = 0; i < 4; i++)
    {
        block[i].setCol(block[i].getCol()-1);
        block[i].setColor(newColor);
    }
}

void Spawn::fall()
{
    for(int i = 0; i < 4; i++)
    {
        block[i].setRow(block[i].getRow()+1);
    }
}



void Spawn::setBox(Box& newBox, int index)
{
    block[index] = newBox;
}

Box Spawn::getBox(int a)
{
    return block[a];
}


Spawn Spawn::rotateBlock()
{
    int pivotX = block[2].getRow();
    int pivotY = block[2].getCol();
    int row, col, deltaX, deltaY;
    int delta2X, delta2Y, newX, newY;
    Spawn rotated = Spawn();

    for(int i = 0; i < 4; i++)
    {
        Box newBox = block[i];

        if (i != 2)
        {
            row = block[i].getRow();
            col = block[i].getCol();

            deltaX = pivotX - row;
            deltaY = pivotY - col;


            delta2X = (0 * deltaX) + (-1 * deltaY);
            delta2Y = (1 * deltaX) + (0 * deltaY);


            newX = pivotX + delta2X;
            newY = pivotY + delta2Y;

            newBox.setRow(newX);
            newBox.setCol(newY);
        }

        rotated.setBox(newBox,i);
    }

    return rotated;
}
