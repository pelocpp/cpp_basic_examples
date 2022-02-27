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
        Rectangle(double x1, double y1, double x2, double y2);

        // getter/setter
        double getX1();
        double getY1();
        double getX2();
        double getY2();
        void setX1(double x1);
        void setY1(double y1);
        void setX2(double x2);
        void setY2(double y2);

        // public interface
        double circumference() const;
        double diagonal() const;
        double area() const;
        bool isSquare() const;
        void center(double& x, double& y) const;
        void adjustWidth(double width);
        void adjustHeight(double height);
        void move(double x, double y);
        Rectangle intersection(const Rectangle& rect) const;

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
