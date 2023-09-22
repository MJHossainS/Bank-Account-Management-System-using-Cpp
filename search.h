#ifndef SEARCH_H
#define SEARCH_H

#include "create_customer.h"
#include <vector>
#include <iostream>

const Customer* searchAndDisplayCustomer(const std::vector<Customer>& customers, int id) {
    for (const auto& customer : customers) {
        if (customer.getCustomerId() == id) {
            std::cout << "Customer ID: " << customer.getCustomerId() << std::endl;
            std::cout << "Full Name: " << customer.full_name << std::endl;
            std::cout << "Date of Birth: " << customer.date_of_birth << std::endl;
            std::cout << "Address: " << customer.address << std::endl;
            std::cout << "Phone Number: " << customer.phone_number << std::endl;
            std::cout << "Email: " << customer.email << std::endl;
            std::cout << "Account Balance: $" << customer.account_balance << std::endl;

            return &customer;
        }
    }
    std::cout << "Customer with ID " << id << " not found." << std::endl;
    return nullptr;
}

#endif  // SEARCH_H
