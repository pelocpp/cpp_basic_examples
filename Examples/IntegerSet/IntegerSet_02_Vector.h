// ===============================================================================
// IntegerSet: Variant 2 - Modern Approach (STL container class 'std::vector')
// ===============================================================================

#pragma once

#include <iostream>
#include <vector>
#include <stdexcept>

namespace IntegerSetVector {

    class IntegerSet
    {
    public:
        // c'tor(s)
        IntegerSet() = default;
        IntegerSet(std::vector<int> numbers);  // user-defined c'tor

    public:
        // getter
        size_t size() const;
        bool isEmpty() const;

        // public methods
        bool insert(int);
        bool remove(int);
        bool contains(int) const;

        // miscellaneous operators
        friend bool operator== (const IntegerSet&, const IntegerSet&);
        friend bool operator!= (const IntegerSet&, const IntegerSet&);

        const int& operator[](size_t idx) const;  // read-only index operator

        // arithmetic-assignment operators
        friend const IntegerSet& operator+= (IntegerSet&, const IntegerSet&);
        friend const IntegerSet& operator-= (IntegerSet&, const IntegerSet&);

        // set theory specific methods
        IntegerSet unionset(const IntegerSet&) const;
        IntegerSet difference(const IntegerSet&) const;
        IntegerSet intersection(const IntegerSet&) const;
        bool isPartial(const IntegerSet&) const;

        // set theory specific operators
        friend IntegerSet operator+ (const IntegerSet&, const IntegerSet&);
        friend IntegerSet operator- (const IntegerSet&, const IntegerSet&);
        friend IntegerSet operator^ (const IntegerSet&, const IntegerSet&);
        friend bool operator<= (const IntegerSet&, const IntegerSet&);

        // output operator
        friend std::ostream& operator<< (std::ostream&, const IntegerSet&);

    private:
        // private member data
        std::vector<int> m_set;

        //int  m_num;  // current number of elements
        //int* m_set;  // array of elements
    };
}

// ===============================================================================
// End-of-File
// ===============================================================================
