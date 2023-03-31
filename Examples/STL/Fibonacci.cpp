// ===========================================================================
// Fibonacci.cpp
// ===========================================================================

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>

// Function Object / Functor
class Fibonacci
{
private:
    int m_first;
    int m_second;

public:
    Fibonacci() : m_first(0), m_second(1) {}

    int operator() ()
    {
        // store current Fibonacci number
        int last = m_first;

        // calculate next pair
        int tmp = m_first + m_second;
        m_first = m_second;
        m_second = tmp;

        return last;
    }

    void operator() (int elem)
    {
        std::cout << ">: " << elem << std::endl;
    }
};

void main_fibonacci()
{
    std::vector<int> numbers(20);

    Fibonacci fibo;

    std::generate(
        numbers.begin(),
        numbers.end(),
        fibo
    );

    std::for_each(
        numbers.begin(),
        numbers.end(),
        fibo
    );
}

// ===========================================================================
// End-of-File
// ===========================================================================
