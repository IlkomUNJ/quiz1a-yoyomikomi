#ifndef BUYER_H
#define BUYER_H

#include <cstddef>
#include <string>
#include "bank_customer.h"
#include <vector>
#include "seller.h"

using namespace std;

class Buyer {
private:
    int id;
    string name;
    BankCustomer &account; // Association with BankCustomer

public:
    Buyer(int id, const string& name, BankCustomer &account0)
        : id(id), name(name), account(account0) {}

    int getId() const { return id; }
    string getName() const { return name; }
    const BankCustomer& getAccount() const {return account;}

    void setId(int newId) { id = newId; }
    void setName(const std::string& newName) { name = newName; }

    void checkAccountStatus(const vector<seller> &sellers) const;
    void upgradeToSeller(Buyer&buyer);
    void createBankingAccount(int id, const string&name, double initialDeposit);
};

#endif // BUYER_H