// ===========================================================================
// Program.cpp
// ===========================================================================

#include "Rectangle_01.h"
#include "Rectangle_02.h"

namespace Rectangle_01 {

    // testing function prototypes
    void test01_ctors();
    void test02_methods();
    void test03_center();
    void test04_adjust();
    void test05_move();
    void test06_intersection();

    void test01_ctors()
    {
        Rectangle rect1;
        std::cout << rect1 << std::endl;
        Rectangle rect2(3, 3, 5, 5);
        std::cout << rect2 << std::endl;
        Rectangle rect3(3, 3, 5, 1);
        std::cout << rect3 << std::endl;
        Rectangle rect4(3, 3, 1, 1);
        std::cout << rect4 << std::endl;
        Rectangle rect5(3, 3, 1, 5);
        std::cout << rect5 << std::endl;
    }

    void test02_methods()
    {
        Rectangle rect(3, 4, 9, 10);
        std::cout << rect << std::endl;
        std::cout << "Circumference: " << rect.circumference() << std::endl;
        std::cout << "Diagonal:      " << rect.diagonal() << std::endl;
        std::cout << "Area:          " << rect.area() << std::endl;
        std::cout << "IsSquare:      " << rect.isSquare() << std::endl;
    }

    void test03_center()
    {
        double x, y;
        Rectangle rect1(1, 3, 3, 1);
        std::cout << rect1 << std::endl;
        rect1.center(x, y);
        std::cout << "Center: (" << x << "," << y << ')' << std::endl;

        Rectangle rect2(1, 4, 4, 1);
        std::cout << rect2 << std::endl;
        rect2.center(x, y);
        std::cout << "Center: (" << x << "," << y << ')' << std::endl;
    }

    void test04_adjust()
    {
        Rectangle rect(3, 3, 1, 1);
        std::cout << rect << std::endl;
        rect.adjustWidth(3);
        std::cout << rect << std::endl;
        rect.adjustWidth(-1);
        std::cout << rect << std::endl;
        rect.adjustHeight(3);
        std::cout << rect << std::endl;
        rect.adjustHeight(-1);
        std::cout << rect << std::endl;
    }

    void test05_move()
    {
        Rectangle rect(1, 1, 4, 5);
        std::cout << rect << std::endl;
        rect.move(5, -5);
        std::cout << rect << std::endl;
    }

    void test06_intersection()
    {
        Rectangle rect1(4, 8, 9, 5);
        Rectangle rect2(2, 10, 8, 6);
        Rectangle rect = rect1.intersection(rect2);
        std::cout << rect << std::endl;

        Rectangle rect3(7, 9, 9, 4);
        rect = rect1.intersection(rect3);
        std::cout << rect << std::endl;

        rect = rect3.intersection(rect3);
        std::cout << rect << std::endl;

        Rectangle rect4(6, 7, 10, 5);
        rect = rect1.intersection(rect4);
        std::cout << rect << std::endl;
    }

    void test_version_01() {
        test01_ctors();
        test02_methods();
        test03_center();
        test04_adjust();
        test05_move();
        test06_intersection();
    }
}

namespace Rectangle_02 {

    void test01_ctors()
    {
        Rectangle rect1;
        std::cout << rect1 << std::endl;
        Rectangle rect2(3, 3, 5, 5);
        std::cout << rect2 << std::endl;
        Rectangle rect3(3, 3, 5, 1);
        std::cout << rect3 << std::endl;
        Rectangle rect4(3, 3, 1, 1);
        std::cout << rect4 << std::endl;
        Rectangle rect5(3, 3, 1, 5);
        std::cout << rect5 << std::endl;
        Point p1(3, 3);
        Point p2(1, 2);
        Rectangle rect6(p1, p2);
        std::cout << rect6 << std::endl;
    }

    void test02_methods()
    {
        Rectangle rect(3, 4, 9, 10);
        std::cout << rect << std::endl;
        std::cout << "Circumference: " << rect.circumference() << std::endl;
        std::cout << "Diagonal:      " << rect.diagonal() << std::endl;
        std::cout << "Area:          " << rect.area() << std::endl;
        std::cout << "IsSquare:      " << rect.isSquare() << std::endl;
    }

    void test03_center()
    {
        Rectangle rect1(1, 3, 3, 1);
        std::cout << rect1 << std::endl;
        Point p = rect1.center();
        std::cout << "Center: (" << p.getX() << "," << p.getY() << ')' << std::endl;

        Rectangle rect2(1, 4, 4, 1);
        std::cout << rect2 << std::endl;
        p = rect2.center();
        std::cout << "Center: (" << p.getX() << "," << p.getY() << ')' << std::endl;
    }

    void test04_adjust()
    {
        Rectangle rect(3, 3, 1, 1);
        std::cout << rect << std::endl;
        rect.adjustWidth(3);
        std::cout << rect << std::endl;
        rect.adjustWidth(-1);
        std::cout << rect << std::endl;
        rect.adjustHeight(3);
        std::cout << rect << std::endl;
        rect.adjustHeight(-1);
        std::cout << rect << std::endl;
    }

    void test05_move()
    {
        Rectangle rect(1, 1, 4, 5);
        std::cout << rect << std::endl;
        rect.move(5, -5);
        std::cout << rect << std::endl;
    }

    void test06_intersection()
    {
        Rectangle rect1(4, 8, 9, 5);
        Rectangle rect2(2, 10, 8, 6);
        Rectangle rect = rect1.intersection(rect2);
        std::cout << rect << std::endl;

        Rectangle rect3(7, 9, 9, 4);
        rect = rect1.intersection(rect3);
        std::cout << rect << std::endl;

        rect = rect3.intersection(rect3);
        std::cout << rect << std::endl;

        Rectangle rect4(6, 7, 10, 5);
        rect = rect1.intersection(rect4);
        std::cout << rect << std::endl;
    }

    void test_version_02() {
        test01_ctors();
        test02_methods();
        test03_center();
        test04_adjust();
        test05_move();
        test06_intersection();
    }
}

int main()
{
    Rectangle_01::test_version_01();
    Rectangle_02::test_version_02();
    return 0;
}

// ===========================================================================
// End-of-File
// ===========================================================================
