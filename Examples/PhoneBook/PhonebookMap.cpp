// ===========================================================================
// End-of-File
// ===========================================================================

#include "PhonebookMap.h"

#include <iostream>
#include <string>
#include <algorithm>
#include <forward_list>
#include <sstream>
#include <numeric>
#include <unordered_map>
#include <utility>

namespace PhonebookMap {

    // =======================================================================
    // getter

    size_t Phonebook::size() const
    {
        return m_map.size();
    }

    // =======================================================================
    // public interface

    bool Phonebook::insert(const std::string& first, const std::string& last, long number)
    {
        if (contains(first, last)) {
            return false;
        }

        std::string key = namesToKey(first, last);

        std::pair<std::string, long> entry(key, number);

        m_map.insert(entry);

        return true;
    }

    bool Phonebook::contains(const std::string& first, const std::string& last) const
    {
        std::string key = namesToKey(first, last);

        std::unordered_map<std::string, long>::const_iterator pos = m_map.find(key);

        return (pos == m_map.end()) ? false : true;
    }

    bool Phonebook::search(const std::string& first, const std::string& last, long& number) const
    {
        std::string key = namesToKey(first, last);

        std::unordered_map<std::string, long>::const_iterator pos = m_map.find(key);

        if (pos == m_map.end()) {

            std::cout << first << " " << last << " not found!" << std::endl;

            return false;
        }
        else {

            std::pair<std::string, long> result = *pos;

            long tmp = result.second;

            number = tmp;

            return true;
        }
    }

    bool Phonebook::remove(const std::string& first, const std::string& last)
    {
        std::string key = namesToKey(first, last);

        size_t count = m_map.erase(key);

        if (count == 0) {
            return false;
        }
        else {
            return true;
        }
    }

    bool Phonebook::update(const std::string& first, const std::string& last, long number)
    {
        std::string key = namesToKey(first, last);

        std::unordered_map<std::string, long>::iterator pos = m_map.find(key);

        if (pos == m_map.end()) {

            return false;
        }
        else {

            std::pair<const std::string, long>& result = *pos;

            result.second = number;

            return true;
        }
    }

    std::string Phonebook::entryToName(std::pair<std::string, long> entry)
    {
        std::string key = entry.first;

        std::pair<std::string, std::string> paar = Phonebook::keyToNames(key);

        std::string fullName = paar.first + " " + paar.second;

        return fullName;
    }

    std::forward_list<std::string> Phonebook::getNames() const
    {
        std::forward_list<std::string> names;

        std::transform(
            m_map.begin(),
            m_map.end(),
            std::front_inserter(names),
            entryToName
        );

        return names;
    }

    void Phonebook::import(const IPhonebook& otherBook)
    {
        // need access to underlying 'm_map' object
        const Phonebook& book = dynamic_cast<const Phonebook&>(otherBook);

        ContactInserter inserter(*this);

        std::for_each(
            book.m_map.begin(),
            book.m_map.end(),
            inserter
        );
    }

    std::string Phonebook::toString() const
    {
        ContactAppender appender;

        std::string result = std::accumulate(
            m_map.begin(),
            m_map.end(),
            std::string(), // first element
            // Phonebook::appendEntry
            appender
        );

        return result;
    }

    // =======================================================================
    // private helper methods

    std::string Phonebook::namesToKey(const std::string& first, const std::string& last)
    {
        std::string key = first + "_" + last;

        return key;
    }

    std::pair<std::string, std::string> Phonebook::keyToNames(const std::string& key)
    {
        size_t pos_underscore = key.find("_");

        std::string firstName = key.substr(0, pos_underscore);

        std::string lastName = key.substr(pos_underscore + 1);

        std::pair<std::string, std::string> result(firstName, lastName);

        return result;
    }

    // =======================================================================
    // output

    std::ostream& operator<< (std::ostream& os, const Phonebook& book)
    {
        Phonebook::ContactPrinter printer(os);

        std::for_each(
            book.m_map.begin(),
            book.m_map.end(),
            printer
        );

        return os;
    }
}

// ===========================================================================
// End-of-File
// ===========================================================================
