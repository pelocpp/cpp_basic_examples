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
        double m_accountNumber;
        double m_balance;

    public:
        // default c'tor / d'tor
        Account(int account);
        virtual ~Account() = default;

        // getter / setter
        double getAccountNumber() override;
        double getBalance() override;

        // public interface
        void deposit(double amount) final override;
    };
}

// ===============================================================================
// End-of-File
// ===============================================================================
