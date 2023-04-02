// ===========================================================================
// Phonebook.cpp
// ===========================================================================

#include "PhonebookVector.h"

#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>
#include <sstream>

namespace PhonebookVector {

    // getter
    size_t Phonebook::size() const
    {
        return m_vec.size();
    }

    // methods
    bool Phonebook::insert(const std::string& first, const std::string& last, long number)
    {
        if (contains(first, last)) {
            return false;
        }

        Contact contact(first, last, number);
        m_vec.push_back(contact);
        return true;
    }

    bool Phonebook::contains(const std::string& first, const std::string& last) const
    {
        ContactFinder finder(first, last);

        std::vector<Contact>::const_iterator result = std::find_if(
            m_vec.begin(),
            m_vec.end(),
            finder
        );

        return (result != m_vec.end()) ? true : false;
    }

    bool Phonebook::search(const std::string& first, const std::string& last, long& number) const
    {
        ContactFinder finder(first, last);

        std::vector<Contact>::const_iterator result = std::find_if(
            m_vec.begin(),
            m_vec.end(),
            finder
        );

        if (result != m_vec.end()) {
            number = result->getNumber();
            return true;
        }
        else {
            return false;
        }
    }

    bool Phonebook::remove(const std::string& first, const std::string& last)
    {
        ContactFinder finder(first, last);

        std::vector<Contact>::iterator it = std::remove_if(
            m_vec.begin(),
            m_vec.end(),
            finder
        );

        bool success = it != m_vec.end();
        if (success) {
            m_vec.erase(it, m_vec.end());
        }

        return success;
    }

    bool Phonebook::update(const std::string& first, const std::string& last, long number)
    {
        ContactFinder finder(first, last);

        std::vector<Contact>::iterator result = std::find_if(
            m_vec.begin(),
            m_vec.end(),
            finder
        );

        if (result != m_vec.end()) {
            result->setNumber(number);
            return true;
        }
        else {
            return false;
        }
    }

    std::forward_list<std::string> Phonebook::getNames() const
    {
        std::forward_list<std::string> names;

        ContactTransformer transform;

        std::transform(
            m_vec.begin(),
            m_vec.end(),
            std::front_inserter(names),
            transform
        );

        return names;
    }

    std::string Phonebook::toString() const
    {
        ContactAppender appender;

        std::string result = std::accumulate(
            m_vec.begin(),
            m_vec.end(),
            std::string(), // first element
            appender
        );

        return result;
    }

    void Phonebook::import(const IPhonebook& otherBook)
    {
        ContactInserter inserter (*this);

        // need access to underlying 'm_vec' object
        const Phonebook& book = dynamic_cast<const Phonebook&>(otherBook);

        std::for_each(
            book.m_vec.begin(),
            book.m_vec.end(),
            inserter
        );
    }

    std::ostream& operator<<(std::ostream& os, const Phonebook& book)
    {
        Phonebook::ContactPrinter printer (std::cout);

        std::for_each(
            book.m_vec.begin(),
            book.m_vec.end(),
            printer
        );

        return os;
    }
}

// ===========================================================================
// End-of-File
// ===========================================================================
