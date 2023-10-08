// ===========================================================================
// Rectangle.cpp // Version 03
// ===========================================================================

#include "Rectangle_03.h"

namespace Rectangle_03 {

    // c'tor(s)
    Rectangle::Rectangle() : Rectangle(0.0, 0.0, 0.0, 0.0) {}

    Rectangle::Rectangle(double top, double left, double width, double height)
    {
        m_top = top;
        m_left = left;

        if (width >= 0.0) {
            m_width = width;
        }
        else {
            m_width = 0.0;
        }

        if (height >= 0.0) {
            m_height = height;
        }
        else {
            m_height = 0.0;
        }
    }

    // getter/setter
    double Rectangle::getTop() const { return m_top; }
    double Rectangle::getLeft() const { return m_left; }
    double Rectangle::getWidth() const { return m_width; }
    double Rectangle::getHeight() const { return m_height; }

    void Rectangle::setTop(double top)
    {
        m_top = top;
    }

    void Rectangle::setLeft(double left)
    {
        m_left = left;
    }

    void Rectangle::setWidth(double width)
    {
        if (width >= 0.0) {
            m_width = width;
        }
        else {
            std::cout << "Expected positive value for 'width': " << width << std::endl;
        }
    }

    void Rectangle::setHeight(double height)
    {
        if (height >= 0.0) {
            m_height = height;
        }
        else {
            std::cout << "Expected positive value for 'height: " << height << std::endl;
        }
    }

    // methods
    void Rectangle::move(double x, double y)
    {
        m_left += x;
        m_top += y;
    }

    double Rectangle::circumference() const
    {
        return 2.0 * (m_width + m_height);
    }

    double Rectangle::area() const
    {
        return m_width * m_height;
    }

    bool Rectangle::isSquare() const
    {
        return m_width == m_height;
    }

    void Rectangle::center(double& x, double& y) const 
    {
        x = m_left + m_width / 2.0;
        y = m_top + m_height / 2.0;
    }

    void Rectangle::adjustWidth(double width)
    {
        m_width = width;
    }

    void Rectangle::adjustHeight(double height)
    {
        m_height = height;
    }

    double Rectangle::diagonal() const
    {
        return std::sqrt(
            m_width * m_width + m_height * m_height
        );
    }

    Rectangle Rectangle::intersection(const Rectangle& rect) const
    {
        if (m_top + m_height < rect.m_top) {
            Rectangle empty;
            return empty;
        }
        else if (m_top > rect.m_top + rect.m_height) {
            Rectangle empty;
            return empty;
        }

        if (m_left + m_width < rect.m_left) {
            Rectangle empty;
            return empty;
        }
        else if (rect.m_left + rect.m_width < m_left) {
            Rectangle empty;
            return empty;
        }

        double left, width;

        if (m_left < rect.m_left) {
            left = rect.m_left;
            width = m_left + m_width - left;
        }
        else {
            left = m_left;
            width = rect.m_left + rect.m_width - left;
        }

        double top, height;

        if (m_top < rect.m_top) {
            top = rect.m_top;
            height = m_top + m_height - top;
        }
        else {
            top = m_top;
            height = rect.m_top + rect.m_height - top;
        }

        Rectangle result(left, top, width, height);

        return result;
    }

    // =======================================================================
    // global operators

    bool operator == (const Rectangle& left, const Rectangle& right)
    {
        if (left.getTop() != right.getTop()) {
            return false;
        }
        else if (left.getLeft() != right.getLeft()) {
            return false;
        }
        else if (left.getWidth() != right.getWidth()) {
            return false;
        }
        else if (left.getHeight() != right.getHeight()) {
            return false;
        }
        else {
            return true;
        }
    }

    bool operator != (const Rectangle& left, const Rectangle& right) {

        return !(left == right);
    }

    // output
    std::ostream& operator << (std::ostream& os, const Rectangle& rect)
    {

        os << "Rectangle: (" << rect.getLeft() << ',' << rect.getTop() << "),(Width="
            << rect.getWidth() << ", Height=" << rect.getHeight() << ") ";

        os
            << "[Area=" << rect.area()
            << ", Circumference=" << rect.circumference()
            << ", IsSquare=" << rect.isSquare() << ']';

        return os;
    }
}

// ===========================================================================
// End-of-File
// ===========================================================================
