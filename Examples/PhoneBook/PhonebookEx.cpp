// ===========================================================================
// Phonebook.cpp
// ===========================================================================

#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>
#include <sstream>


#include "PhoneBookEx.h"


namespace PhonebookVector {


    // ===========================================================================
    // class Phonebook - public interface

    size_t Phonebook::size() const
    {
        return m_vec.size();
    }

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
            m_vec.begin(),                 // Quelle - Anfang
            m_vec.end(),                   // Quelle - Ende
            std::front_inserter(names),    // Ziel -Anfang  // Achtung: Verwende Proxy
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

    void Phonebook::import(const IPhonebook& ibook)
    {
        //// need access to underlying 'm_vec' object
        //const Phonebook& book = dynamic_cast<const Phonebook&>(ibook);

        //std::for_each(
        //    book.m_vec.begin(),
        //    book.m_vec.end(),
        //    Inserter(*this)
        //);
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
// class Phonebook - helper classes providing functors for STL algorithms

//void Phonebook::Printer::operator() (const Contact& contact)
//{
//    m_os << contact << std::endl;
//}
//
//bool Phonebook::Comparer::operator() (const Contact& contact1, const Contact& contact2)
//{
//    if (contact1.getlast() == contact2.getlast()) {
//        return contact1.getfirst() < contact2.getfirst();
//    }
//    else {
//        return contact1.getlast() < contact2.getlast();
//    }
//}
//
//bool Phonebook::SearcherContact::operator() (const Contact& contact)
//{
//    if (contact.getfirst() == m_first && contact.getlast() == m_last) {
//        return true;
//    }
//    else {
//        return false;
//    }
//}
//
//bool Phonebook::Searcherlast::operator() (const Contact& contact)
//{
//    if (contact.getlast() == m_last) {
//        return true;
//    }
//    else {
//        return false;
//    }
//}
//
//void Phonebook::Inserter::operator() (const Contact& contact)
//{
//    m_book.insert(contact);
//};
//
//std::string Phonebook::Appender::operator() (const std::string& first, const Contact& next)
//{
//    std::ostringstream ss;
//    ss << next.getfirst() << ", "
//        << next.getlast() << ": "
//        << next.getNumber() << std::endl;
//
//    return first + ss.str();
//}
//
//bool Phonebook::SearcherFullNameAndNumber::operator() (const Contact& contact) {
//
//    if (contact.getfirst() == m_first &&
//        contact.getlast() == m_last &&
//        contact.getNumber() == m_number) {
//        return true;
//    }
//    else {
//        return false;
//    }
//}

// ===========================================================================
// End-of-File
// ===========================================================================
