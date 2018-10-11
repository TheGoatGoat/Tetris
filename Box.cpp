#include "Box.h"

Box::Box(int rowNum, int colNum, Color myColor)
{
    activated = false;
    isSpawn = false;
    row = rowNum;
    col = colNum;
    p1 = Point(colNum*30+1,rowNum*30+1);
    p2 = Point((colNum+1)*30-1,(rowNum+1)*30-1);
    c = myColor;
}

void Box::setRow(int newRow)
{
    row = newRow;
    p1 = Point(col*30+1,row*30+1);
    p2 = Point((col+1)*30-1,(row+1)*30-1);
}

void Box::setCol(int newCol)
{
    col = newCol;
    p1 = Point(col*30+1,row*30+1);
    p2 = Point((col+1)*30-1,(row+1)*30-1);
}

void Box::activate()
{
    activated = true;
}

void Box::deactivate()
{
    activated = false;
    isSpawn = false;
    c = Color(0, 0, 0);
}

void Box::setColor(Color newColor)
{
    c = newColor;
}

void Box::setSpawn()
{
    isSpawn = true;
}

void Box::notSpawn()
{
    isSpawn = false;
}



bool Box::checkActivation()
{
    return activated;
}

bool Box::checkSpawn()
{
    return isSpawn;
}

int Box::getRow()
{
    return row;
}

int Box::getCol()
{
    return col;
}



void Box::draw(SDL_Plotter& g)
{
    for(int x = p1.x; x <= p2.x; x++)
        {
        for(int y = p1.y; y <= p2.y; y++)
        {
            g.plotPixel(x, y, c.R, c.G, c.B);
        }
    }
}
