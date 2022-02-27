// ===========================================================================
// Point.cpp
// ===========================================================================

#include "Point.h"

// c'tor(s)
Point::Point() : Point(0, 0) {}
Point::Point(double x, double y) : m_x(x), m_y(y) {}

// getter/setter
double Point::getX() const { return m_x; }
double Point::getY() const { return m_y; }
void Point::setX(double x) { m_x = x; };
void Point::setY(double y) { m_y = y; };

// output
std::ostream& operator << (std::ostream& os, const Point& p)
{
    os << '[' << p.getX() << ',' << p.getY() << ']';
    return os;
}

// ===========================================================================
// End-of-File
// ===========================================================================
