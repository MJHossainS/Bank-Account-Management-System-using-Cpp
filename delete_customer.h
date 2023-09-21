#ifndef DELETE_CUSTOMER_H
#define DELETE_CUSTOMER_H

#include <vector>
#include "create_customer.h"

class CustomerDeletion {
private:
    std::vector<Customer>& customers;
public:
    CustomerDeletion(std::vector<Customer>& custs) : customers(custs) {}

    bool deleteCustomerById(int id) {
        for (auto it = customers.begin(); it != customers.end(); ++it) {
            if (it->getCustomerId() == id) {
                customers.erase(it);
                return true;  // Successfully deleted
            }
        }
        return false;  // No matching customer found
    }

};

#endif
