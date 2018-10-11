#include "Line.h"

Line::Line()
{
    p1 = Point(0,0);
    p2 = Point(50,50);
    color = Color(255,255,255);
    width = 1;
}

Line::Line(Point a, Point b, Color c, int w)
{
    p1 = a;
    p2 = b;
    color = c;
    width = w;
}


void Line::setP1(const Point& p)
{
    p1 = p;
}

void Line::setP2(const Point& p)
{
    p2 = p;
}

void Line::setColor(const Color& c)
{
    color = c;
}

void Line::setWidth(const int w)
{
    width = w;
}


Point Line::getP1() const
{
    return p1;
}

Point Line::getP2() const
{
    return p2;
}

Color Line::getColor() const
{
    return color;
}

int Line::getWidth() const
{
    return width;
}


bool Line::slope(double& m) const
{
    bool hasSlope = false;

    hasSlope = p1.x != p2.x;
    if(hasSlope){
        m = static_cast<double>(p1.y - p2.y)/(p1.x - p2.x);
    }

    return hasSlope;
}

double Line::y_intercept() const
{
    double m;
    slope(m);

    // b = y - mx;
    return p1.y - m*p1.x;
}


void Line::draw(SDL_Plotter& g) const
{
    double m,b,y;

    if(slope(m)){
        b = y_intercept();
        for(double x = min(p1.x, p2.x); x <= max(p1.x, p2.x); x += 0.001){
            y = m*x+b;
            for(int w = width/2; w <= width/2; w++){
                g.plotPixel(x+w, y, color.R, color.G, color.B);
            }
        }
    }
    else{
        for(int y = min(p1.y, p2.y); y <= max(p1.y, p2.y); y++){
            for(int w = width/2; w <= width/2; w++){
                g.plotPixel(p1.x+w, y, color.R, color.G, color.B);
            }
        }
    }
}
