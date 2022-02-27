// ===============================================================================
// Rectangle.h // Version 02
// ===============================================================================

#pragma once

#include <iostream>

#include "Point.h"

namespace Rectangle_02 {

    class Rectangle
    {
    private:
        Point m_p1;
        Point m_p2;

    public:
        // c'tors
        Rectangle();
        Rectangle(Point p1, Point p2);
        Rectangle(double x1, double y1, double x2, double y2);

        // getter/setter
        //double getX1() const;
        //double getY1() const;
        //double getX2() const;
        //double getY2() const;
        Point getLeftUpper() const;
        Point getRightLower() const;
        //void setX1(double x);
        //void setY1(double y);
        //void setX2(double x);
        //void setY2(double y);
        void setLeftUpper(const Point&);
        void setRightLower(const Point&);

        // public interface
        double circumference() const;
        double diagonal() const;
        double area() const;
        bool isSquare() const;
        Point center() const;
        void adjustWidth(double width);
        void adjustHeight(double height);
        void move(double x, double y);
        Rectangle intersection(const Rectangle& rect) const;

    private:
        // private helper methods
        void normalize();
    };

    std::ostream& operator<< (std::ostream&, const Rectangle&);
}

// ===============================================================================
// End-of-File
// ===============================================================================
