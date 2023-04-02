// ===========================================================================
// PhonebookMap.h
// ===========================================================================

#pragma once

#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>

#include "IPhonebook.h"

namespace PhonebookMap {


    class Phonebook : public IPhonebook
    {
        friend std::ostream& operator<< (std::ostream&, const Phonebook&);

        friend void printEntry(const std::pair<std::string, long>& entry);

      //  friend std::string appendEntry(const std::string& first, std::pair<std::string, long> entry);

      //  friend std::string appendEntry(const std::string& first, std::pair<std::string, long> entry);


    private:
        class ContactInserter
        {
        private:
            Phonebook& m_book;

        public:
            ContactInserter(Phonebook& book) : m_book(book) {}

            void operator() (const std::pair<std::string, long>& entry)
            {
                std::pair<std::string, std::string> names = keyToNames(entry.first);

                std::string firstName = names.first;
                std::string lastName = names.second;

                m_book.insert(firstName, lastName, entry.second);
            }
        };

    private:
        std::unordered_map<std::string, long> m_map;

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

    private:
        // helper methods
        static std::pair<std::string, std::string> keyToNames(const std::string& key);
        static std::string namesToKey(const std::string& first, const std::string& last);

        static std::string entryToName(std::pair<std::string, long> entry);

         static std::string appendEntry(const std::string& first, std::pair<std::string, long> entry);
    };
}

// ===========================================================================
// End-of-File
// ===========================================================================
