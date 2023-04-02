// ===========================================================================
// PhonebookVector.h
// ===========================================================================

#pragma once

#include "IPhonebook.h"

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

namespace PhonebookVector {

    class Phonebook : public IPhonebook
    {
        friend std::ostream& operator<<(std::ostream&, const Phonebook&);

    private:
        class Contact
        {
        public:
            Contact(const std::string& first, const std::string& last, long number)
                : m_first(first), m_last(last), m_number(number) {}

        private:
            std::string m_first;
            std::string m_last;
            long m_number;

        public:
            // getter / setter
            const std::string& firstName() const { return m_first; }
            const std::string& lastName()  const { return m_last; }

            long getNumber() const { return m_number; }
            void setNumber(long number) { m_number = number; }
        };

        // nested helper classes - providing function object for STL algorithm
        class ContactFinder
        {
        private:
            std::string m_first;
            std::string m_last;

        public:
            ContactFinder(const std::string& first, const std::string& last)
                : m_first(first), m_last(last) {}

            bool operator() (const Contact& contact)
            {
                if (contact.firstName() == m_first && contact.lastName() == m_last) {
                    return true;
                }
                else {
                    return false;
                }
            }
        };

        class ContactTransformer
        {
        public:

            std::string operator() (const Contact& contact)
            {
                std::string name = contact.firstName() + " " + contact.lastName();
                return name;
            }
        };

        class ContactAppender
        {
        public:
            std::string operator() (const std::string& first, const Contact& next)
            {
                std::ostringstream ss;

                ss << next.firstName() << " "
                    << next.lastName() << ": "
                    << next.getNumber() << std::endl;

                return first + ss.str();
            }
        };

        class ContactInserter
        {
        private:
            Phonebook& m_book;

        public:
            ContactInserter(Phonebook& book) : m_book(book) {}

            void operator() (const Contact& contact)
            {
                m_book.insert(contact.firstName(), contact.lastName(), contact.getNumber());
            }
        };

        class ContactPrinter
        {
        private:
            std::ostream& m_os;

        public:
            ContactPrinter(std::ostream& os) : m_os(os) {}

            void operator() (const Contact& contact)
            {
                m_os << contact.firstName() << ", "
                    << contact.lastName() << ": "
                    << contact.getNumber()
                    << std::endl;
            }
        };

        std::vector<Contact> m_vec;

    public:
        // getter
        size_t size() const final override;

        // public interface
        bool insert(const std::string& first, const std::string& last, long number) override;
        bool contains(const std::string& first, const std::string& last) const override;
        bool search(const std::string& first, const std::string& last, long& number) const override;
        bool remove(const std::string& first, const std::string& last) override;
        bool update(const std::string& first, const std::string& last, long number) override;

        std::forward_list<std::string> getNames() const;
        void import(const IPhonebook& book) override;
        std::string toString() const override;
    };
}

// ===========================================================================
// End-of-File
// ===========================================================================
