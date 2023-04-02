// ===========================================================================
// IPhonebook.h
// ===========================================================================

#pragma once

#include <iostream>
#include <string>
#include <forward_list>

class IPhonebook
{
    // getter
    virtual size_t size() const = 0;

    // methods
    virtual bool insert(const std::string& first, const std::string& last, long number) = 0;
    virtual bool contains(const std::string& first, const std::string& last) const = 0;
    virtual bool search(const std::string& first, const std::string& last, long& number) const = 0;
    virtual bool remove(const std::string& first, const std::string& last) = 0;
    virtual bool update(const std::string& first, const std::string& last, long number) = 0;

    virtual std::forward_list<std::string> getNames() const = 0;
    virtual void import(const IPhonebook& book) = 0;
    virtual std::string toString() const = 0;
};

// ===========================================================================
// End-of-File
// ===========================================================================
