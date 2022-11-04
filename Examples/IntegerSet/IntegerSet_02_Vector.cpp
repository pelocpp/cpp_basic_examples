// ===============================================================================
// IntegerSet: Variant 2 - Modern Approach (STL container class 'std::vector')
// ===============================================================================

#include "IntegerSet_02_Vector.h"

namespace IntegerSetVector {

    // c'tors and d'tor
    IntegerSet::IntegerSet(std::vector<int> numbers) {
        for (int n : numbers) {
            insert(n);
        }
    }

    // getter
    size_t IntegerSet::size() const {
        return m_set.size();
    }

    bool IntegerSet::isEmpty() const {
        return m_set.size() == 0;
    }

    // public methods
    bool IntegerSet::contains(int n) const {

        // search element
        std::vector<int>::const_iterator pos = std::find(
            m_set.begin(),
            m_set.end(),
            n
        );

        return (pos != m_set.end()) ? true : false;
    }

    bool IntegerSet::insert(int n) {

        // element already exists
        if (contains(n))
            return false;

        m_set.push_back(n);
        return true;
    }

    bool IntegerSet::remove(int n) {

        std::vector<int>::const_iterator pos = std::remove(
            m_set.begin(),
            m_set.end(),
            n
        );

        // element found, delete it
        if (pos != m_set.end()) {
            m_set.erase(pos);
            return true;
        }
        else {
            return false; // element not found
        }
    }

    // operators
    bool operator== (const IntegerSet& lhs, const IntegerSet& rhs) {

        // compare sizes
        if (lhs.m_set.size() != rhs.m_set.size())
            return false;

        // compare both sets element per element
        for (size_t i = 0; i < lhs.m_set.size(); i++) {

            if (rhs.contains(lhs.m_set[i]))
                continue;

            return false;
        }

        return true;
    }

    bool operator!= (const IntegerSet& lhs, const IntegerSet& rhs) {
        return !(lhs == rhs);
    }

    const int& IntegerSet::operator[](size_t n) const {

        // check parameter
        if (n < 0)
            throw std::out_of_range("Wrong Index in subscript operator");
        if (n >= m_set.size())
            throw std::out_of_range("Wrong Index in subscript operator");

        return m_set[n];
    }

    // arithmetic-assignment operators
    const IntegerSet& operator+= (IntegerSet& lhs, const IntegerSet& rhs) {

        for (size_t i = 0; i < rhs.m_set.size(); i++)
            lhs.insert(rhs.m_set[i]);

        return lhs;
    }

    const IntegerSet& operator-= (IntegerSet& lhs, const IntegerSet& rhs) {

        for (size_t i = 0; i < rhs.m_set.size(); i++)
            lhs.remove(rhs.m_set[i]);

        return lhs;
    }

    // set theory specific methods
    IntegerSet IntegerSet::unionset(const IntegerSet& rhs) const {
        IntegerSet set(*this);
        for (size_t i = 0; i < rhs.m_set.size(); i++)
            set.insert(rhs.m_set[i]);

        return set;
    }

    IntegerSet IntegerSet::difference(const IntegerSet& rhs) const {
        IntegerSet set(*this);
        for (size_t i = 0; i < rhs.m_set.size(); i++)
            set.remove(rhs.m_set[i]);

        return set;
    }

    IntegerSet IntegerSet::intersection(const IntegerSet& rhs) const {
        IntegerSet set;
        for (size_t i = 0; i < m_set.size(); i++) {
            int n = m_set[i];
            if (rhs.contains(n))
                set.insert(n);
        }
        return set;
    }

    bool IntegerSet::isPartial(const IntegerSet& rhs) const {
        // compare both sets element per element
        for (size_t i = 0; i < m_set.size(); i++) {
            int n = m_set[i];
            if (!rhs.contains(n))
                return false;
        }

        return true;
    }

    // set theory specific operators
    IntegerSet operator+ (const IntegerSet& lhs, const IntegerSet& rhs) {
        return lhs.unionset(rhs);
    }

    IntegerSet operator- (const IntegerSet& lhs, const IntegerSet& rhs) {
        return lhs.difference(rhs);
    }

    IntegerSet operator^ (const IntegerSet& lhs, const IntegerSet& rhs) {
        return lhs.intersection(rhs);
    }

    bool operator<= (const IntegerSet& lhs, const IntegerSet& rhs) {
        return lhs.isPartial(rhs);
    }

    // output operator
    std::ostream& operator<< (std::ostream& os, const IntegerSet& set) {
        os << "{";
        for (size_t i = 0; i < set.m_set.size(); i++) {
            os << set.m_set[i];
            if (i < set.m_set.size() - 1)
                os << ',';
        }
        os << "} [" << set.m_set.size() << "]";

        return os;
    }
}

// ===============================================================================
// End-of-File
// ===============================================================================
