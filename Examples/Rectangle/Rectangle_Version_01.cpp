// ===========================================================================
// Rectangle.cpp // Version 01
// ===========================================================================

#include <iostream>
#include <cmath>

#include "Rectangle_01.h"

namespace Rectangle_01 {

    // c'tor(s)
    Rectangle::Rectangle() : Rectangle(0.0, 0.0, 0.0, 0.0) {}

    Rectangle::Rectangle(double x1, double y1, double x2, double y2)
        : m_x1(x1), m_y1(y1), m_x2(x2), m_y2(y2)
    {
        normalize();
    }

    // getter/setter
    double Rectangle::getX1() { return m_x1; }
    double Rectangle::getY1() { return m_y1; }
    double Rectangle::getX2() { return m_x2; }
    double Rectangle::getY2() { return m_y2; }

    void Rectangle::setX1(double x1)
    {
        m_x1 = x1;
        normalize();
    }

    void Rectangle::setY1(double y1)
    {
        m_y1 = y1;
        normalize();
    }

    void Rectangle::setX2(double x2)
    {
        m_x2 = x2;
        normalize();
    }

    void Rectangle::setY2(double y2)
    {
        m_y2 = y2;
        normalize();
    }

    // methods
    double Rectangle::circumference() const
    {
        return 2 * ((m_x2 - m_x1) + (m_y1 - m_y2));
    }

    double Rectangle::diagonal() const
    {
        return std::sqrt(
            (m_x2 - m_x1) * (m_x2 - m_x1) + (m_y1 - m_y2) * (m_y1 - m_y2)
        );
    }

    double Rectangle::area() const
    {
        return (m_x2 - m_x1) * (m_y1 - m_y2);
    }

    bool Rectangle::isSquare() const
    {
        return (m_x2 - m_x1) == (m_y1 - m_y2);
    }

    void Rectangle::center(double& x, double& y) const
    {
        x = m_x1 + (m_x2 - m_x1) / 2.0;
        y = m_y2 + (m_y1 - m_y2) / 2.0;
    }

    void Rectangle::adjustWidth(double width)
    {
        m_x2 = m_x1 + width;
        normalize();
    }

    void Rectangle::adjustHeight(double height)
    {
        m_y2 = m_y1 - height;
        normalize();
    }

    void Rectangle::move(double x, double y)
    {
        m_x1 += x;
        m_y1 += y;
        m_x2 += x;
        m_y2 += y;
    }

    Rectangle Rectangle::intersection(const Rectangle& r) const
    {
        double x1, y1, x2, y2;

        if (m_x2 <= r.m_x1 || m_x1 >= r.m_x2 ||
            m_y1 <= r.m_y2 || m_y2 >= r.m_y1)
        {
            return Rectangle();
        }

        if (m_x1 < r.m_x1)
        {
            x1 = r.m_x1;
        }
        else
        {
            x1 = m_x1;
        }

        if (m_x2 < r.m_x2)
        {
            x2 = m_x2;
        }
        else
        {
            x2 = r.m_x2;
        }

        if (m_y1 > r.m_y1)
        {
            y1 = r.m_y1;
        }
        else
        {
            y1 = m_y1;
        }

        if (m_y2 > r.m_y2)
        {
            y2 = m_y2;
        }
        else
        {
            y2 = r.m_y2;
        }

        return Rectangle(x1, y1, x2, y2);
    }

    // output
    std::ostream& operator << (std::ostream& os, const Rectangle& r)
    {
        os << "Rectangle: (" << r.m_x1 << ',' << r.m_y1 << "),("
            << r.m_x2 << ',' << r.m_y2 << ") ";
        os << "[Area=" << r.area() << ", Circumference=" << r.circumference()
            << ", Diagonal=" << r.diagonal() << ", IsSquare=" << r.isSquare() << ']';

        return os;
    }

    // private helper methods
    void Rectangle::normalize()
    {
        if (m_x1 > m_x2)
        {
            double tmp = m_x1;
            m_x1 = m_x2;
            m_x2 = tmp;
        }

        if (m_y1 < m_y2)
        {
            double tmp = m_y1;
            m_y1 = m_y2;
            m_y2 = tmp;
        }
    }
}

// ===========================================================================
// End-of-File
// ===========================================================================
