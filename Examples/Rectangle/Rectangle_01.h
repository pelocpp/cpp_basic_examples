// ===============================================================================
// Rectangle.h // Version 01
// ===============================================================================

#pragma once

#include <iostream>

namespace Rectangle_01 {

    class Rectangle
    {
    private:
        double m_x1;
        double m_y1;
        double m_x2;
        double m_y2;

    public:
        // c'tors
        Rectangle();
        Rectangle(double, double, double, double);

        // getter/setter
        double getX1();
        double getY1();
        double getX2();
        double getY2();
        void setX1(double);
        void setY1(double);
        void setX2(double);
        void setY2(double);

        // public interface
        double circumference() const;
        double diagonal() const;
        double area() const;
        bool isSquare() const;
        void center(double& x, double& y) const;
        void adjustWidth(double);
        void adjustHeight(double);
        void move(double, double);
        Rectangle intersection(const Rectangle&) const;

    private:
        // private helper methods
        void normalize();

        // output
        friend std::ostream& operator << (std::ostream&, const Rectangle&);
    };
}

// ===============================================================================
// End-of-File
// ===============================================================================
