// ===========================================================================
// Point.h
// ===========================================================================

#pragma once

#include <iostream>

class Point
{
private:
    double m_x;
    double m_y;

public:
    // c'tor(s)
    Point();
    Point(double x, double y);

    // getter/setter
    double getX() const;
    double getY() const;
    void setX(double x);
    void setY(double y);
};

std::ostream& operator << (std::ostream&, const Point&);

// ===========================================================================
// End-of-File
// ===========================================================================
