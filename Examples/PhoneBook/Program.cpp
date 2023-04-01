// ===========================================================================
// Program.cpp // Phonebook Main Program
// ===========================================================================

#include <iostream>
#include <string>
#include <algorithm>

#include "PhonebookEx.h"
 
using namespace PhonebookVector;

// function prototypes
void main_phonebook_01();
void main_phonebook_02();
void main_phonebook_03();
void main_phonebook_04();
void main_phonebook_05();
void main_phonebook_06();

void initPhoneBook(Phonebook& book)
{
    book.insert("Hans", "Mueller", 12345);
    book.insert("Sepp", "Wagner", 54321);
    book.insert("Georg", "Huber", 13579);
    book.insert("Anton", "Meier", 86420);
    book.insert("Peter", "Wagner", 95735);
}

void main_phonebook_01()
{
    Phonebook book;

    initPhoneBook(book);
    std::cout << book << std::endl;

    bool found = book.contains("Sepp", "Wagner");
    std::cout << std::boolalpha << "Sepp Wagner found: " << found << std::endl;

    found = book.contains("Sepp", "Huber");
    std::cout << std::boolalpha << "Sepp Huber found: " << found << std::endl;
}


void main_phonebook_02()
{
    Phonebook book;

    initPhoneBook(book);
    std::cout << book << std::endl;

    long number = 0;
    bool found = book.search("Sepp", "Wagner", number);
    std::cout << "Sepp has number " << number << std::endl;

    bool result = book.remove("Sepp", "Wagner");
    std::cout << "Removed Sepp: " << std::boolalpha << result << std::endl << std::endl;

    std::cout << book << std::endl;
}

void main_phonebook_03()
{
    Phonebook book;

    initPhoneBook(book);
    std::cout << book << std::endl;

    long number = 0;
    bool found = book.search("Sepp", "Wagner", number);
    std::cout << "Sepp has number " << number << std::endl;

    book.update("Sepp", "Wagner", 1122334455);
    std::cout << "Updated number of Sepp" << std::endl;

    found = book.search("Sepp", "Wagner", number);
    std::cout << "Sepp now has number " << number << std::endl;
}

void printName(const std::string& name) {
    std::cout << ">: " << name << std::endl;
}

void main_phonebook_04()
{
    Phonebook book;
    initPhoneBook(book);

    std::forward_list<std::string> names = book.getNames();

    std::for_each(
        names.begin(),
        names.end(),
        printName
    );
}

void main_phonebook_05()
{
    Phonebook book1;
    book1.insert("Hans", "Mueller", 12345);
    book1.insert("Sepp", "Wagner", 54321);
    book1.insert("Georg", "Huber", 13579);
    std::cout << book1 << std::endl;

    Phonebook book2;
    book2.insert("Anton", "Meier", 86420);
    book2.insert("Peter", "Wagner", 95735);
    book2.insert("Georg", "Huber", 13579);
    book2.insert("Manfred", "Schmidt", 6452353);
    std::cout << book2 << std::endl;

    book1.import(book2);
    std::cout << book1 << std::endl;
}

void main_phonebook_06()
{
    Phonebook book;
    initPhoneBook(book);
    std::cout << book.toString() << std::endl;
}


int main()
{
    main_phonebook_01();
    main_phonebook_02();
    main_phonebook_03();
    main_phonebook_04();
    main_phonebook_05();
    main_phonebook_06();

    return 0;
}

// ===========================================================================
// End-of-File
// ===========================================================================

//
void ausgabe(const std::string& name) {
    std::cout << "Name: " << name << std::endl;
}

void main_phonebook()
{
    Phonebook book;

    book.insert("Hubert", "Mueller", 123456);
    book.insert("Anton", "Huber", 354534);
    book.insert("Sepp", "Meier", 8723223);
    book.insert("Wolfang", "Wagner", 8723223);

    // Range-Based for Loop
    for (auto& elem : book) {

        std::string key = elem.firstName();

        //std::string first;
        //std::string last;

        //Phonebook::keyToNames(key, first, last);

        //std::cout << first << "  " << last << ": " << elem.second << std::endl;
    }
}
//
//
//void main_phonebook_zum_zweiten()
//{
//    Phonebook book;
//
//    book.insert("Hubert", "Mueller", 123456);
//    book.insert("Anton", "Huber", 354534);
//    book.insert("Sepp", "Meier", 8723223);
//
//    std::cout << book << std::endl;
//}
//
//
//void main_phonebook_zum_ersten()
//{
//    Phonebook book;
//
//    book.insert("Hubert", "Mueller", 123456);
//    book.insert("Anton", "Huber", 354534);
//    book.insert("Sepp", "Meier", 8723223);
//
//    book.print();
//
//    long phoneNumber = 0;
//
//    bool found = book.search("Anton", "Huber", phoneNumber);
//
//    if (found) {
//
//        std::cout << "Anton Huber hat die Tel.Nr. " << phoneNumber << std::endl;
//    }
//
//    book.remove("Sepp", "Meier");
//
//    book.print();
//
//    // ====================================
//    // Erstelle Liste mit allen Namen aus dem Tel.Buch:
//
//    std::forward_list<std::string> names = book.getNames();
//
//    std::for_each(
//        names.begin(),
//        names.end(),
//        ausgabe
//    );
//}
