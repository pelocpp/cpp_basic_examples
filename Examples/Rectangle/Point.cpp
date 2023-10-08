// ===========================================================================
// Point.cpp
// ===========================================================================

#include "Point.h"

namespace Rectangle_02 {

    // c'tor(s)
    Point::Point() : Point(0, 0) {}
    Point::Point(double x, double y) : m_x(x), m_y(y) {}

    // getter/setter
    double Point::getX() const { return m_x; }
    double Point::getY() const { return m_y; }
    void Point::setX(double x) { m_x = x; }
    void Point::setY(double y) { m_y = y; }

    // operator helpers
    Point Point::operator+ (const Point& p)
    {
        return Point(m_x + p.m_x, m_y + p.m_y);
    }

    Point& Point::operator+= (const Point& p)
    {
        *this = *this + p;
        return *this;
    }

    // global operators
    bool operator == (const Point& p1, const Point& p2) {

        return p1.getX() == p2.getX() && p1.getY() == p2.getY();
    }

    bool operator != (const Point& p1, const Point& p2) {

        return ! (p1 == p2);
    }

    // output
    std::ostream& operator << (std::ostream& os, const Point& p)
    {
        os << '[' << p.getX() << ',' << p.getY() << ']';
        return os;
    }
}

// ===========================================================================
// End-of-File
// ===========================================================================
