// ===========================================================================
// Rectangle.cpp // Version 02
// ===========================================================================

#include <iostream>
#include <cmath>

#include "Point.h"
#include "Rectangle_02.h"

namespace Rectangle_02 {

    // c'tor(s)
    Rectangle::Rectangle() : m_p1(0.0, 0.0), m_p2(0.0, 0.0) {}

    Rectangle::Rectangle(Point p1, Point p2) : m_p1(p1), m_p2(p2)
    {
        normalize();
    }

    Rectangle::Rectangle(double x1, double y1, double x2, double y2)
        : m_p1(x1, y1), m_p2(x2, y2)
    {
        normalize();
    }

    // getter/setter
    Point Rectangle::getLeftUpper() const
    {
        return m_p1;
    }

    Point Rectangle::getRightLower() const
    { 
        return m_p2;
    }

    void Rectangle::setLeftUpper(const Point& p)
    {
        m_p1 = p;
        normalize();
    }

    void Rectangle::setRightLower(const Point& p)
    {
        m_p2 = p;
        normalize();
    }

    // methods
    double Rectangle::circumference() const
    {
        return 2 * ((m_p2.getX() - m_p1.getX()) + (m_p1.getY() - m_p2.getY()));
    }

    double Rectangle::diagonal() const
    {
        return std::sqrt((
            (m_p2.getX() - m_p1.getX()) * (m_p2.getX() - m_p1.getX()) +
            (m_p1.getY() - m_p2.getY()) * (m_p1.getY() - m_p2.getY()))
        );
    }

    double Rectangle::area() const
    {
        return (m_p2.getX() - m_p1.getX()) * (m_p1.getY() - m_p2.getY());
    }

    bool Rectangle::isSquare() const
    {
        return (m_p2.getX() - m_p1.getX()) == (m_p1.getY() - m_p2.getY());
    }

    Point Rectangle::center() const
    {
        return Point(
            m_p1.getX() + (m_p2.getX() - m_p1.getX()) / 2.0,
            m_p2.getY() + (m_p1.getY() - m_p2.getY()) / 2.0
        );
    }

    void Rectangle::adjustWidth(double width)
    {
        m_p2.setX(m_p1.getX() + width);
        normalize();
    }

    void Rectangle::adjustHeight(double height)
    {
        m_p2.setY(m_p1.getY() - height);
        normalize();
    }

    void Rectangle::move(const Point& p)
    {
        m_p1 += p;
        m_p2 += p;
    }

    Rectangle Rectangle::intersection(const Rectangle& r) const
    {
        double x1, y1, x2, y2;

        if (m_p2.getX() <= r.m_p1.getX() || m_p1.getX() >= r.m_p2.getX() ||
            m_p1.getY() <= r.m_p2.getY() || m_p2.getY() >= r.m_p1.getY())
        {
            return Rectangle();
        }

        if (m_p1.getX() < r.m_p1.getX())
        {
            x1 = r.m_p1.getX();
        }
        else
        {
            x1 = m_p1.getX();
        }

        if (m_p2.getX() < r.m_p2.getX())
        {
            x2 = m_p2.getX();
        }
        else
        {
            x2 = r.m_p2.getX();
        }

        if (m_p1.getY() > r.m_p1.getY())
        {
            y1 = r.m_p1.getY();
        }
        else
        {
            y1 = m_p1.getY();
        }

        if (m_p2.getY() > r.m_p2.getY())
        {
            y2 = m_p2.getY();
        }
        else
        {
            y2 = r.m_p2.getY();
        }

        return Rectangle(x1, y1, x2, y2);
    }

    // output
    std::ostream& operator << (std::ostream& os, const Rectangle& r)
    {
        os << "Rectangle: " << r.getLeftUpper() << ',' << r.getRightLower() << ' ';
        os << "[Area=" << r.area() << ", Circumference=" << r.circumference()
            << ", Diagonal=" << r.diagonal() << ", IsSquare=" << r.isSquare() << ']';

        return os;
    }

    // private helper methods
    void Rectangle::normalize()
    {
        if (m_p1.getX() > m_p2.getX())
        {
            double tmp = m_p1.getX();
            m_p1.setX(m_p2.getX());
            m_p2.setX(tmp);
        }

        if (m_p1.getY() < m_p2.getY())
        {
            double tmp = m_p1.getY();
            m_p1.setY(m_p2.getY());
            m_p2.setY(tmp);
        }
    }
}

// ===========================================================================
// End-of-File
// ===========================================================================
