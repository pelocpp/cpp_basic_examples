// ===========================================================================
// Point.h
// ===========================================================================

#pragma once

#include <iostream>

namespace Rectangle_02 {

    class Point
    {
    private:
        double m_x;
        double m_y;

    public:
        // c'tor(s)
        Point();
        Point(double, double);

        // getter/setter
        double getX() const;
        double getY() const;
        void setX(double);
        void setY(double);

        // operators
        Point operator+ (const Point&);
        Point& operator+= (const Point&);
    };

    // =======================================================================
    // global operators
    bool operator == (const Point&, const Point&);
    bool operator != (const Point&, const Point&);

    std::ostream& operator << (std::ostream&, const Point&);
}

// ===========================================================================
// End-of-File
// ===========================================================================
