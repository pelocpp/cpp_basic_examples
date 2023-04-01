// ===========================================================================
// End-of-File
// ===========================================================================

#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <forward_list>

#include <unordered_map>
#include <utility>

#include "PhonebookMap.h"


namespace PhonebookMap {


    size_t Phonebook::size() const
    {
        return m_map.size();
    }

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

    bool Phonebook::contains(const std::string& first, const std::string& last)
    {
        std::string key = namesToKey(first, last);

        std::unordered_map<std::string, long>::iterator pos = m_map.find(key);

        return (pos == m_map.end()) ? false : true;
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

    // TODO das kann man static machen !!!!!!!!!!!!!!!!!!!
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
            m_map.begin(),                 // Quelle - Anfang
            m_map.end(),                   // Quelle - Ende
            std::front_inserter(names),    // Ziel -Anfang  // Achtung: Verwende Proxy
            entryToName
        );

        return names;
    }

    void printEntry(const std::pair<std::string, long>& entry)
    {
        std::string key = entry.first;   // "Anton_Huber"

        // 1. Variante:
        std::pair<std::string, std::string> names = Phonebook::keyToNames(key);

        std::cout
            << "Vorname: " << names.first
            << ", Nachname: " << names.second << ": "
            << entry.second << std::endl;

        // 2. Variante:

        //std::string firstName;
        //std::string lastName;

        //Phonebook::keyToNames(key, firstName, lastName);

        //std::cout
        //    << "Vorname: " << firstName
        //    << ", Nachname: " << lastName << ": "
        //    << entry.second << std::endl;
    }

    //void Phonebook::print() const
    //{
    //    std::for_each(
    //        m_map.begin(),
    //        m_map.end(),
    //        printEntry
    //    );
    //}






    // =========================================================
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

    // oder

    void Phonebook::keyToNames(const std::string& key, std::string& first, std::string& last)
    {
        size_t pos_underscore = key.find("_");

        first = key.substr(0, pos_underscore);

        last = key.substr(pos_underscore + 1);
    }

    // ========================================================

    // globale Funktion

    std::ostream& operator<< (std::ostream& os, const Phonebook& book)
    {
        // book.print();

        return os;
    }
}


// ===========================================================================
// End-of-File
// ===========================================================================
