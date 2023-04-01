// ===========================================================================
// IPhonebook.h
// ===========================================================================

#pragma once
#pragma once

#include <iostream>
#include <string>
#include <unordered_map>
#include <map>
#include <utility>

#include "IPhonebook.h"

namespace PhonebookMap {


    class Phonebook : public IPhonebook
    {
        friend std::ostream& operator<< (std::ostream&, const Phonebook&);

    private:
        std::unordered_map<std::string, long> m_map;

    public:
        // getter
        size_t size() const final override;

        // public interface
        bool insert(const std::string& first, const std::string& last, long number) override;

        bool search(const std::string& first, const std::string& last, long& number) const override;

        /* [[ nodiscard ]] */ bool remove(const std::string& first, const std::string& last) override;

        bool update(const std::string& first, const std::string& last, long number) override;

        std::forward_list<std::string> getNames() const override;

        // void print() const override;

    public:
        // iterator support - delegating to underlying STL container
        std::unordered_map<std::string, long>::iterator begin() { return m_map.begin(); }
        std::unordered_map<std::string, long>::iterator end() { return m_map.end(); }

    public:
        // helper methods
        static std::pair<std::string, std::string> keyToNames(const std::string& key);
        // oder
        static void keyToNames(const std::string& key, std::string& first, std::string& last);

        static std::string namesToKey(const std::string& first, const std::string& last);

        static std::string entryToName(std::pair<std::string, long> entry);

    private:
        bool contains(const std::string& first, const std::string& last);
    };

}
// ===========================================================================
// End-of-File
// ===========================================================================
