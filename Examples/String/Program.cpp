// ===========================================================================
// Program.cpp
// ===========================================================================

#include <iostream>

#include "String.h"

void TestCtorsDtor()
{
    // Test c'tors
    String s1;
    std::cout << "s1: " << s1 << std::endl;
    String s2("12345");
    std::cout << "s2: " << s2 << std::endl;
    String s3(s2);
    std::cout << "s3: " << s3 << std::endl;
}

void TestInsert()
{
    String s1("12678");
    s1.insert("345", 2);
    std::cout << "s1: " << s1 << std::endl;

    String s2("ABCD");
    s2.insert(s1, 2);
    std::cout << "s2: " << s2 << std::endl;

    s2.insert("!", 13);
    std::cout << "s2: " << s2 << std::endl;

    s2.insert(".", 12);
    std::cout << "s2: " << s2 << std::endl;

    s2.insert(".", 0);
    std::cout << "s2: " << s2 << std::endl;
}

void TestAppend()
{
    String s1;
    s1.append("123");
    std::cout << "s1: " << s1 << std::endl;

    String s2("ABC");
    s2.append("DEF");
    std::cout << "s2: " << s2 << std::endl;
}

void TestRemove()
{
    String s1("12345");
    s1.remove(1, 3);
    std::cout << "s1: " << s1 << std::endl;

    String s2("ABC");
    s2.remove(0, 3);
    std::cout << "s2: " << s2 << std::endl;
}

void TestSubString()
{
    String s2("ABCDE");
    String s;
    s = s2.subString(1, 3);
    std::cout << "s: " << s << std::endl;
    s = s2.subString(0, 5);
    std::cout << "s: " << s << std::endl;
    s = s2.subString(0, 6);
    std::cout << "s: " << s << std::endl;
    s = s2.subString(0, 0);
    std::cout << "s: " << s << std::endl;
}

void TestOperators()
{
    // Test '=' operator
    String s1;
    String s2("12345");
    s1 = s2;
    std::cout << "s1: " << s1 << std::endl;

    // Test '==' operator
    std::cout << "s1 == s2: " << (s1 == s2) << std::endl;
    s1.remove(0, 1);
    std::cout << "s1 == s2: " << (s1 == s2) << std::endl;
    std::cout << "s1 != s2: " << (s1 != s2) << std::endl;
}

void TestInput()
{
    String s;
    std::cout << "Enter string: ";
    std::cin >> s;
    std::cout << "String: " << s << '.' << std::endl;
}

void TestLeftRight()
{
    String s("12345");
    String s1;
    String s2;

    s1 = s.left(3);
    std::cout << "Left(3):  " << s1 << '.' << std::endl;
    s2 = s.right(2);
    std::cout << "Right(2): " << s2 << '.' << std::endl;

    s1 = s.left(5);
    std::cout << "Left(5):  " << s1 << '.' << std::endl;
    s2 = s.right(5);
    std::cout << "Right(5): " << s2 << '.' << std::endl;

    s1 = s.left(6);
    std::cout << "Left(6):  " << s1 << '.' << std::endl;
    s2 = s.right(6);
    std::cout << "Right(6): " << s2 << '.' << std::endl;
}

void TestToUpperToLower()
{
    String s("aBcDeFgHiJkLmNoPqRsTuVwXyZ");
    std::cout << "s:" << s << '.' << std::endl;
    s.toUpper();
    std::cout << "s:" << s << '.' << std::endl;
    s.toLower();
    std::cout << "s:" << s << '.' << std::endl;
}

void TestFind()
{
    String s("ABCDEFGHIJKLMN");
    int i = s.find("IJK");
    std::cout << "i: " << i << std::endl;

    i = s.find("ABCDEFGHIJKLMN");
    std::cout << "i: " << i << std::endl;

    i = s.find("IJKZ");
    std::cout << "i: " << i << std::endl;

    i = s.find("N");
    std::cout << "i: " << i << std::endl;

    i = s.find("Z");
    std::cout << "i: " << i << std::endl;

    i = s.find("");
    std::cout << "i: " << i << std::endl;
}

void TestSubsriptOperator()
{
    String s("ABCDE");
    std::cout << "s[0]: " << s[0] << std::endl;
    std::cout << "s[4]: " << s[4] << std::endl;

    s[0] = '<';
    s[4] = '>';
    std::cout << "s: " << s << std::endl;

    try
    {
        s[5] = '!';
    }
    catch (std::out_of_range& e)
    {
        std::cout << e.what() << std::endl;
    }
}

void TestStringConcatenation()
{
    String s1("123");
    String s2("ABC");
    String s3;

    s3 = s1 + s2;
    std::cout << "s1:" << s1 << std::endl;
    std::cout << "s2:" << s2 << std::endl;
    std::cout << "s3:" << s3 << std::endl;

    s1 += s2 += "789";
    std::cout << "s1:" << s1 << std::endl;
    std::cout << "s2:" << s2 << std::endl;
}

int main()
{
    TestCtorsDtor();
    TestInsert();
    TestAppend();
    TestRemove();
    TestSubString();
    TestOperators();
    TestInput();
    TestLeftRight();
    TestToUpperToLower();
    TestFind();
    TestSubsriptOperator();
    TestStringConcatenation();

    return 0;
}

// ===========================================================================
// End-of-File
// ===========================================================================
