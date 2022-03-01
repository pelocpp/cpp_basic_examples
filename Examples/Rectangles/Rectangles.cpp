// ===========================================================================
// Rectangles.cpp
// ===========================================================================

#include <iostream>

namespace Rectangles {

    class IRectangle
    {
    public:
        virtual void draw() = 0;
        virtual void drawForeground() = 0;
        virtual void drawBorder() = 0;
        virtual void eraseBackground() = 0;
    };

    class IPersistence
    {
    public:
        virtual void save() = 0;
    };

    // ----------------------------------------------------------------

    class Rectangle : public IRectangle
    {
    protected:
        int m_x;
        int m_y;
        int m_width;
        int m_height;

    public:
        Rectangle() : Rectangle(0, 0, 0, 0) {};

        Rectangle(int x, int y, int width, int height) 
            : m_x(x), m_y(y), m_width(width), m_height(height) {};

        virtual void drawBorder() override final {
            std::cout 
                << "  Rectangle::drawBorder: width=" << m_width
                << ", height: " << m_height << std::endl;
        }

        virtual void eraseBackground() override final {
            std::cout << "  Rectangle::eraseBackground" << std::endl;
        }

        virtual void draw() override final {
            std::cout << "Rectangle::draw [x=" << m_x << ", y=" << m_y << "]" << std::endl;
            eraseBackground();
            drawForeground();
            drawBorder();
        }
    };

    // ------------------------------------------

    class ColoredRectangle : public Rectangle
    {
    public:
        ColoredRectangle() : ColoredRectangle(0, 0, 0, 0, 0.0) {}

        ColoredRectangle(int x, int y, int width, int height, double color)
            : Rectangle(x, y, width, height), m_hsv(123) {}

        void paint() {
            std::cout 
                << "  ColoredRectangle::paint: width=" << m_width 
                << ", height: " << m_height << std::endl;
        }

        virtual void drawForeground() override {
            std::cout << "  ColoredRectangle::drawForeground" << std::endl;
        }

    private:
        double m_hsv;  // hue, saturation, value
    };

    // ------------------------------------------

    class BlackWhiteRectangle : public Rectangle
    {
    public:
        BlackWhiteRectangle() : BlackWhiteRectangle(0, 0, 0, 0, 0.0) {}

        BlackWhiteRectangle(int x, int y, int width, int height, double color)
            : Rectangle(x, y, width, height), m_monochrom(111) {}

        virtual void drawForeground() override {
            std::cout << "  BlackWhiteRectangle::drawForeground" << std::endl;
        }

    private:
        int m_monochrom;  // monochromatic value
    };

    // ------------------------------------------

    class HatchedColoredRectangle : public ColoredRectangle
    {
    public:
        HatchedColoredRectangle() : HatchedColoredRectangle(0, 0, 0, 0, 0.0, 0.0) {}

        HatchedColoredRectangle(int x, int y, int width, int height, double color, double strokeThickness)
            : ColoredRectangle(x, y, width, height, color), m_strokeThickness(strokeThickness) {}

        void paint() {
            std::cout 
                << "  HatchedColoredRectangle::paint: width=" << m_width 
                << ", height: " << m_height << std::endl;
        }

        virtual void drawForeground() override {
            std::cout << "  HatchedColoredRectangle::drawForeground" << std::endl;
        }

    private:
        double m_strokeThickness;
    };
}

void test_01()
{
    using namespace Rectangles;

    HatchedColoredRectangle hcr;
    ColoredRectangle& crRef(hcr);
    crRef.paint();
}

void test_02()
{
    using namespace Rectangles;

    HatchedColoredRectangle hcr;

    ColoredRectangle& crRef (hcr);
    // or
    ColoredRectangle* crPtr(& hcr);

    crRef.draw();
    // or
    crPtr->draw();
}

void test_03()
{
    using namespace Rectangles;

    ColoredRectangle cr1(1, 1, 20, 30, 255);
    BlackWhiteRectangle br2(2, 2, 30, 40, 111.0);
    ColoredRectangle cr3(3, 3, 50, 60, 127);

    IRectangle* rects[]{ &cr1, &br2, &cr3 };
    for (int i = 0; i < 3; ++i) {
        rects[i]->draw();
    }
}
// ===========================================================================
// End-of-File
// ===========================================================================
