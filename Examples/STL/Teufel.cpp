// ===========================================================================
// Teufel.cpp
// ===========================================================================

#include <iostream>
#include <vector>
#include <algorithm>

void printToConsole(int value) {
    std::cout << ">: " << value << std::endl;
}

void main_teufel_01()
{
    std::vector<int> teufelFolge;

    int start = 7;

    teufelFolge.push_back(start);

    while (start != 1)
    {
        // greedy calculation
        start = (start % 2 == 0) ? (start / 2) : (start * 3 + 1);
        teufelFolge.push_back(start);
    }

    std::for_each(
        teufelFolge.begin(),
        teufelFolge.end(),
        printToConsole
    );
}

// ===========================================================================
// Advanced Solution - Using STL Iterator Concept

class CollatzIterator
{
public:
    using iterator_category = std::forward_iterator_tag;
    using value_type = int;
    using difference_type = int;
    using pointer = int*;
    using reference = int&;

private:
    int m_start;
    int m_current;
    int m_last;

public:
    // c'tors
    CollatzIterator(int start)
        : m_start(start), m_current(start), m_last(start)
    {}

    // operators
    int operator*() const {
        return m_current;
    }

    CollatzIterator& operator++()
    {
        m_last = m_current;

        m_current = (m_current % 2 == 0)
            ? m_current = m_current / 2
            : m_current = 3 * m_current + 1;

        return *this;
    }

    bool operator!=(const CollatzIterator& iter) const
    {
        return m_last != iter.m_current;
    }
};

class CollatzSequence
{
private:
    int m_start;

public:
    // c'tor(s)
    CollatzSequence(int start) : m_start(start) {}

    // iterator support
    CollatzIterator begin() const { return CollatzIterator(m_start); }
    CollatzIterator end()   const { return CollatzIterator(1); }
};

// using std::for_each
void main_teufel_02()
{
    CollatzSequence seq(7);

    // lazy calculation
    std::for_each(
        seq.begin(),
        seq.end(),
        printToConsole
    );
    std::cout << std::endl;
}

// using std::copy
void main_teufel_03()
{
    CollatzSequence seq(7);

    std::vector<int> numbers;

    // greedy calculation
    std::copy(
        seq.begin(),
        seq.end(),
        std::back_inserter(numbers)
    );

    std::for_each(
        numbers.begin(),
        numbers.end(),
        printToConsole
    );

    std::cout << std::endl;
}

// using range-based for-loop
void main_teufel_04()
{
    CollatzSequence seq(7);

    for (int number : seq) {
        std::cout << number << " ";
    }
    std::cout << std::endl;
}

void main_teufel()
{
    main_teufel_01();
    main_teufel_02();
    main_teufel_03();
    main_teufel_04();
}

// ===========================================================================
// End-of-File
// ===========================================================================
