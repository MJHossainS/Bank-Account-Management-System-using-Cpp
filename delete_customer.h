#ifndef DELETE_CUSTOMER_H
#define DELETE_CUSTOMER_H

#include "create_customer.h"
#include <vector>
#include <iostream>
#include <algorithm>

class CustomerDeletion {
private:
    std::vector<Customer> customers;

    // Private helper function to find a customer's position by ID
    std::vector<Customer>::iterator findCustomerPositionById(int id) {
        return std::find_if(customers.begin(), customers.end(),
                            [id](const Customer& c) { return c.getCustomerId() == id; });
    }

public:
    // Function to add a customer (might be useful later)
    void addCustomer(const Customer& customer) {
        customers.push_back(customer);
    }

    // Delete a customer by their ID
    bool deleteCustomerById(int id) {
        auto it = findCustomerPositionById(id);
        if (it != customers.end()) {
            std::cout << "Deleting customer: " << it->full_name << " with ID: " << id << std::endl;
            customers.erase(it);
            return true;
        } else {
            std::cout << "Customer with ID " << id << " not found." << std::endl;
            return false;
        }
    }
};

#endif  // DELETE_CUSTOMER_H
