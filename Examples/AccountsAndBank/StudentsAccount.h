// ===============================================================================
// StudentsAccount.h // Demo Implementation Inheritance (Accounts and Bank)
// ===============================================================================

#pragma once

#include <iostream>

#include "Account.h"

namespace AccountsAndBank {

    class StudentsAccount final : public Account
    {
        friend std::ostream& operator<< (std::ostream&, const StudentsAccount&);

    public:
        // c'tors
        StudentsAccount(int accountNumber);
        virtual ~StudentsAccount() {};

        // public interface
        bool withdraw(double amount) override;
        void print(std::ostream& os) override;
    };
}
    
// ===============================================================================
// End-of-File
// ===============================================================================
