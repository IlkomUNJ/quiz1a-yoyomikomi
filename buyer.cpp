#include <iostream>
#include "buyer.h"
#include "seller.h"
#include "bank_customer.h"
#include <vector>
using namespace std;

extern vector<seller> sellers;
void Buyer::checkAccountStatus(const vector<seller> &sellers) const {
    cout <<"--Account Status--"<< endl;
    cout << "Buyer ID:" << id << endl;
    cout << "Buyer Name"<< name<<endl;
}

void Buyer::upgradeToSeller(Buyer&buyer) {
    string sellerName;
    cout << "Enter seller name: "<< endl;
    cin >> sellerName;

    int sellerId = buyer.getId(); // Use buyer's ID
    seller newSeller(buyer, sellerId, sellerName);
    sellers.push_back(newSeller);
}

void createBankingAccount(int id, const string& name, double initialDeposit) {
    BankCustomer account(id, name, initialDeposit);
    cout << "Banking account created." << endl;
}