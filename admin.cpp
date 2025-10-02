#include "admin.h"
#include <iostream>
#include <algorithm>

Admin::Admin() {
    // Constructor can be empty or used for setup
}

void Admin::viewAllUsers(const std::vector<Buyer>& buyers, const std::vector<seller>& sellers) {
    std::cout << "=== All Buyers ===" << std::endl;
    for (const auto& b : buyers) {
        std::cout << "Buyer ID: " << b.getId() << ", Name: " << b.getName() << std::endl;
    }

    std::cout << "\n=== All Sellers ===" << std::endl;
    for (const auto& s : sellers) {
        std::cout << "Seller ID: " << s.getId() << ", Name: " << s.getName() << std::endl;
    }
}

void Admin::viewUserDetails(const std::vector<Buyer>& buyers, const std::vector<seller>& sellers) {
    std::cout << "=== Buyer Details ===" << std::endl;
    for (const auto& b : buyers) {
        std::cout << "ID: " << b.getId() << ", Name: " << b.getName() << std::endl;
        b.getAccount().printInfo();
        std::cout << "------------------------" << std::endl;
    }

    std::cout << "\n=== Seller Details ===" << std::endl;
    for (const auto& s : sellers) {
        std::cout << "ID: " << s.getId() << ", Name: " << s.getName() << std::endl;
        s.getAccount().printInfo();
        std::cout << "------------------------" << std::endl;
    }
}

void Admin::searchUser(const std::vector<Buyer>& buyers, const std::vector<seller>& sellers) {
    std::cout << "Search by:\n1. Name\n2. Account ID\nEnter choice: ";
    int choice;
    std::cin >> choice;
    std::cin.ignore();

    std::string query;
    std::cout << "Enter search term: ";
    std::getline(std::cin, query);

    bool found = false;

    if (choice == 1) {
        for (const auto& b : buyers) {
            if (b.getName() == query) {
                std::cout << "Buyer Found: ID " << b.getId() << std::endl;
                b.getAccount().printInfo();
                found = true;
            }
        }
        for (const auto& s : sellers) {
            if (s.getName() == query) {
                std::cout << "Seller Found: ID " << s.getId() << std::endl;
                s.getAccount().printInfo();
                found = true;
            }
        }
    } else if (choice == 2) {
        int id = std::stoi(query);
        for (const auto& b : buyers) {
            if (b.getId() == id) {
                std::cout << "Buyer Found: " << b.getName() << std::endl;
                b.getAccount().printInfo();
                found = true;
            }
        }
        for (const auto& s : sellers) {
            if (s.getId() == id) {
                std::cout << "Seller Found: " << s.getName() << std::endl;
                s.getAccount().printInfo();
                found = true;
            }
        }
    }

    if (!found) {
        std::cout << "No matching user found." << std::endl;
    }
}

void Admin::createUser(std::vector<Buyer>& buyers, std::vector<seller>& sellers, std::vector<BankCustomer>& bankAccounts) {
    std::cout << "Create:\n1. Buyer\n2. Seller\nEnter choice: ";
    int choice;
    std::cin >> choice;
    std::cin.ignore();

    int id;
    std::string name;
    double balance;

    std::cout << "Enter ID: ";
    std::cin >> id;
    std::cin.ignore();
    std::cout << "Enter Name: ";
    std::getline(std::cin, name);
    std::cout << "Enter Initial Balance: ";
    std::cin >> balance;

    BankCustomer account(id, name, balance);
    bankAccounts.push_back(account);

    if (choice == 1) {
        Buyer newBuyer(id, name, bankAccounts.back());
        buyers.push_back(newBuyer);
        std::cout << "Buyer created." << std::endl;
    } else if (choice == 2) {
        Buyer tempBuyer(id, name, bankAccounts.back());
        std::string sellerName;
        std::cout << "Enter Seller Name: ";
        std::cin.ignore();
        std::getline(std::cin, sellerName);
        seller newSeller(tempBuyer, id, sellerName);
        sellers.push_back(newSeller);
        std::cout << "Seller created." << std::endl;
    }
}
