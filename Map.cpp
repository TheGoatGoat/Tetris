#include "Map.h"

Map::Map(){
    rowPixel = 600;
    colPixel = 300;
    for(int i = 0; i < 20; i++){
        for(int j = 0; j < 10; j++){
            myBox[i][j].setRow(i);
            myBox[i][j].setCol(j);
        }
    }

    for(int i = 0; i < 11; i++){
        verticalRule[i].setP1(Point(i*30,0));
        verticalRule[i].setP2(Point(i*30,599));
    }

    for(int i = 0; i < 20; i++){
        horizontalRule[i].setP1(Point(0,i*30));
        horizontalRule[i].setP2(Point(300,i*30));
    }
}

void Map::draw(SDL_Plotter& g){
    for(int i = 0; i < 11; i++){
        verticalRule[i].draw(g);
    }
    for(int i = 0; i < 20; i++){
        horizontalRule[i].draw(g);
    }
}

void Map::drawBox(SDL_Plotter& g){
    for(int i = 0; i < 20; i++){
        for(int j = 0; j < 10; j++){
            myBox[i][j].draw(g);
        }
    }
}

Box Map::getBox(int row, int col){
    return myBox[row][col];
}

void Map::setBox(int row, int col, Box newBox){
    myBox[row][col] = newBox;
}
