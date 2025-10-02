#include "buyer.h"
#include "seller.h"
#include "bank_customer.h"
#include <vector>
#include <string>

class Admin {
public:
    Admin();
    void viewAllUsers(const std::vector<Buyer>& buyers, const std::vector<seller>& sellers);
    void viewUserDetails(const std::vector<Buyer>& buyers, const std::vector<seller>& sellers);
    void searchUser(const std::vector<Buyer>& buyers, const std::vector<seller>& sellers);
    void createUser(std::vector<Buyer>& buyers, std::vector<seller>& sellers, std::vector<BankCustomer>& bankAccounts);
    void removeUserById(std::vector<Buyer>& buyers, std::vector<seller>& sellers, std::vector<BankCustomer>& bankAccounts);
    };