// ===========================================================================
// Phonebook.h
// ===========================================================================

#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "Contact.h"
#include "IPhonebook.h"

class Phonebook : public IPhonebook
{
private:
    std::vector<Contact> m_vec;

public:
    // public helper class - providing functor for STL algorithms
    class Printer
    {
    private:
        std::ostream& m_os;

    public:
        Printer(std::ostream& os) : m_os(os) {}
        void operator() (const Contact& contact);
    };

private:
    // private helper classes - providing functors for STL algorithms
    class SearcherContact
    {
    private:
        const std::string& m_firstName;
        const std::string& m_lastName;

    public:
        SearcherContact(const std::string& firstName, const std::string& lastName)
            : m_firstName(firstName), m_lastName(lastName) {}
        bool operator() (const Contact& contact);
    };

    class SearcherLastName
    {
    private:
        const std::string& m_lastName;

    public:
        SearcherLastName(const std::string& lastName) : m_lastName(lastName) {}
        bool operator() (const Contact& contact);
    };

    class SearcherFullNameAndNumber
    {
    private:
        const std::string& m_firstName;
        const std::string& m_lastName;
        const long m_number;

    public:
        SearcherFullNameAndNumber(const std::string& firstName, const std::string& lastName, long number)
            : m_firstName(firstName), m_lastName(lastName), m_number(number) {}
        bool operator() (const Contact& contact);
    };

    class Inserter
    {
    private:
        Phonebook& m_book;

    public:
        Inserter(Phonebook& book) : m_book(book) {}
        void operator() (const Contact& book);
    };

    struct Appender
    {
    public:
        std::string operator() (const std::string& first, const Contact& next);
    };

    struct Comparer
    {
        bool operator() (const Contact&, const Contact&);
    };

private:
    // wrapping a Standard Library container
    std::vector<Contact>::iterator begin() { return m_vec.begin(); }
    std::vector<Contact>::iterator end() { return m_vec.end(); }

public:
    // public interface
    virtual size_t size() override;
    virtual bool insert(const std::string& firstName, const std::string& lastName, long number) override;
    virtual bool insert(const Contact&) override;
    virtual bool contains(const std::string& firstName, const std::string& lastName) override;
    virtual bool find(const std::string& firstName, const std::string& lastName, long& number) override;
    virtual std::vector<Contact> findAll(const std::string& lastName) override;
    virtual bool remove(const std::string& firstName, const std::string& lastName, long number) override;
    virtual bool update(const std::string& firstName, const std::string& lastName, long number) override;
    virtual void import(const IPhonebook& book) override;
    virtual std::string toString() override;
    virtual void sort() override;

    friend std::ostream& operator<<(std::ostream&, const Phonebook&);
};

// ===========================================================================
// End-of-File
// ===========================================================================
