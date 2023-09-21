#ifndef TRANSACTIONS_H
#define TRANSACTIONS_H

#include "create_customer.h"
#include <vector>
#include <iostream>

class BankTransactions {
private:
    std::vector<Customer> customers;

    // Private helper function to find a customer by ID
    Customer* findCustomerById(int id) {
        for (auto& customer : customers) {
            if (customer.getCustomerId() == id) {
                return &customer;
            }
        }
        return nullptr;
    }

public:
    // Function to add a customer (might be useful later)
    void addCustomer(const Customer& customer) {
        customers.push_back(customer);
    }

    // Deposit money to a specific customer's account using customer ID
    bool depositMoney(int id, double amount) {
        Customer* customer = findCustomerById(id);
        if (customer) {
            customer->account_balance += amount;
            std::cout << "Deposited $" << amount << " to account of " << customer->full_name << ". New balance: $" << customer->account_balance << std::endl;
            return true;
        } else {
            std::cout << "Customer with ID " << id << " not found." << std::endl;
            return false;
        }
    }

    // Withdraw money from a specific customer's account using customer ID
    bool withdrawMoney(int id, double amount) {
        Customer* customer = findCustomerById(id);
        if (customer) {
            if (amount > customer->account_balance) {
                std::cout << "Insufficient funds. Your current balance is: $" << customer->account_balance << std::endl;
                return false;
            } else {
                customer->account_balance -= amount;
                std::cout << "Withdrew $" << amount << " from account of " << customer->full_name << ". Remaining balance: $" << customer->account_balance << std::endl;
                return true;
            }
        } else {
            std::cout << "Customer with ID " << id << " not found." << std::endl;
            return false;
        }
    }


    std::vector<Customer>& getCustomers() {
    return customers;
}

};

#endif  // TRANSACTIONS_H
