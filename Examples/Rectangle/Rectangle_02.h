// ===============================================================================
// Rectangle.h // Version 02
// ===============================================================================

#pragma once

#include <iostream>

#include "Point.h"
#include "Rectangle_02.h"

namespace Rectangle_02 {

    class Rectangle
    {
    private:
        Point m_p1;
        Point m_p2;

    public:
        // c'tors
        Rectangle();
        Rectangle(Point, Point);
        Rectangle(double, double, double, double);

        // getter/setter
        Point getLeftUpper() const;
        Point getRightLower() const;
        void setLeftUpper(const Point&);
        void setRightLower(const Point&);

        // public interface
        double circumference() const;
        double diagonal() const;
        double area() const;
        bool isSquare() const;
        Point center() const;
        void adjustWidth(double);
        void adjustHeight(double);
        void move(const Point&);
        Rectangle intersection(const Rectangle&) const;

    private:
        // private helper methods
        void normalize();
    };

    std::ostream& operator<< (std::ostream&, const Rectangle&);
}

// ===============================================================================
// End-of-File
// ===============================================================================
