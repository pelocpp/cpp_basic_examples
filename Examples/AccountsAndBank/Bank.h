// ===============================================================================
// Bank.h // Demo Implementation Inheritance (Accounts and Bank)
// ===============================================================================

#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "IAccount.h"
#include "Bank.h"

namespace AccountsAndBank {

    constexpr int MaxAccounts = 100;

    class Bank
    {
        friend std::ostream& operator<< (std::ostream&, const Bank&);

    private:
        std::string m_name;
        std::vector<IAccount*> m_accounts;

    private:
        static int g_availableAccountNumber;

    public:
        // c'tors
        Bank(); 
        Bank(std::string name);
        ~Bank();

        // public interface
        int createCurrentAccount(double limit);
        int createDepositAccount(double interestRate);
        int createStudentsAccount();
        bool deleteAccount(int accountNumber);

        bool deposit(int accountNumber, double amount);
        bool withdraw(int accountNumber, double amount);
        bool transfer(int from, int to, double amount);

        // getter / setter
        double getTotalBalance();

    private:
        void deleteAllAccounts();
    };
}
    
// ===============================================================================
// End-of-File
// ===============================================================================
