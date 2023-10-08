// ===============================================================================
// Rectangle.h // Version 03
// ===============================================================================

#pragma once

#include <iostream>

namespace Rectangle_03 {

    class Rectangle
    {
    private:
        double m_top;
        double m_left;
        double m_width;
        double m_height;

    public:
        // c'tors
        Rectangle();
        Rectangle(double top, double left, double width, double height);

        // getter/setter
        double getTop() const;
        double getLeft() const;
        double getWidth() const;
        double getHeight() const;

        void setTop(double top);
        void setLeft(double left);
        void setWidth(double width);
        void setHeight(double height);

        // public interface // methods
        double circumference() const;
        double diagonal() const;
        double area() const;
        bool isSquare() const;
        void center(double& x, double& y) const;
        void adjustWidth(double);
        void adjustHeight(double);
        void move(double, double);
        Rectangle intersection(const Rectangle&) const;
    };

    // ===========================================================================

    // global operators
    bool operator == (const Rectangle&, const Rectangle&);
    bool operator != (const Rectangle&, const Rectangle&);

    std::ostream& operator<< (std::ostream& os, const Rectangle& rect);
}

// ===============================================================================
// End-of-File
// ===============================================================================
