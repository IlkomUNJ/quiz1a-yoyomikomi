#pragma once

#include "buyer.h"
#include "seller.h"
#include "bank_customer.h"
#include <vector>
#include <string>

class Admin {
public:
    // Constructor
    Admin();

    // Admin operations
    void viewAllUsers(const std::vector<Buyer>& buyers, const std::vector<seller>& sellers);
};