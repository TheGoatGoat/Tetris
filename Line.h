#ifndef LINE_H_INCLUDED
#define LINE_H_INCLUDED

#include "Point.h"
#include "Color.h"
#include "SDL_Plotter.h"

class Line{
    private:
        Point p1, p2;
        Color color;
        int width;

    public:
        /*
        description: Default constructor
        return: n/a
        precondition: valid object is  initialized
        postcondition: object is created with default settings
        */
        Line();
        /*
        description: Constructor with parameters
        return: n/a
        precondition: valid object is initialized
        postcondition: Object is created with parameters passed
        */
        Line(Point, Point, Color = Color(0,0,0), int = 1);

        /*
        description: sets the first point
        return: void
        precondition: valid object is created with valid settings
        postcondition: Sets p1 to the point being passed
        */
        void setP1(const Point&);

        /*
        description: sets the second point
        return: void
        precondition: valid object is created with valid settings
        postcondition: sets p2 to the point being passed
        */
        void setP2(const Point&);

        /*
        description: sets the color variable for line
        return: void
        precondition: valid object is created with valid color
        postcondition: sets the color for line object
        */
        void setColor(const Color&);

        /*
        description: sets the width variable in line
        return: void
        precondition: valid object is created with valid width
        postcondition: changes the width for line object
        */
        void setWidth(const int);

        /*
        description: Retrieves coordinates for point p1
        return: Point
        precondition: valid object with p1 is initialized
        postcondition: returns the coordinates for P1
        */
        Point getP1() const;

        /*
        description: retrieves coordinates for point p2
        return: Point
        precondition: valid object with p2 is initialized
        postcondition: returns the coordinates for p2
        */
        Point getP2() const;

        /*
        description: retrieves the color code for the object
        return: Color
        precondition: valid object with color is initialized
        postcondition: returns the color code for the object
        */
        Color getColor() const;

        /*
        description: retrieves the width for the object
        return: int
        precondition: valid object with width is initialized
        postcondition: returns the width
        */
        int getWidth() const;

        /*
        description: calculates the slope of the object
        return: bool
        precondition: valid object with valid variables initialized
        postcondition: returns if slope is valid, and slope of line
        */
        bool slope(double& m) const;

        /*
        description: calculates the y intercept
        return: double
        precondition: valid slope function, and object is initialized
        postcondition: returns the y intercept of the line object.
        */
        double y_intercept() const;

        /*
        description: draws a line
        return: void
        precondition: valid object and SDL_Plotter object is initialized
        postcondition: draws a line on the SDL_Plotter
        */
        void draw(SDL_Plotter&) const;
};
#endif // LINE_H_INCLUDED
