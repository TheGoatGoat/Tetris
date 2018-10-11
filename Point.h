#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED

#include <ostream>
#include <iostream>
#include <cmath>

using namespace std;

struct Point
{
    int x;
    int y;

    Point();
    Point(int a, int b = 0);
};

#endif // POINT_H_INCLUDED
