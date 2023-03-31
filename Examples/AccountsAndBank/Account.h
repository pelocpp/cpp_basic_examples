// ===============================================================================
// Account.h // Demo Implementation Inheritance (Accounts and Bank)
// ===============================================================================

#pragma once

#include <iostream>

#include "IAccount.h"

namespace AccountsAndBank {

    class Account : public IAccount
    {
    protected:
        int m_accountNumber;
        double m_balance;

    public:
        // default c'tor / d'tor
        Account(int account);
        virtual ~Account() {};

        // getter / setter
        double getAccountNumber() final override;
        double getBalance() final override;

        // public interface
        void deposit(double amount) final override;
    };
}

// ===============================================================================
// End-of-File
// ===============================================================================
