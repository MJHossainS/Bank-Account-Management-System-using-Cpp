#include <iostream>
#include "create_customer.h"
#include "search.h"
#include "delete_customer.h"
#include "transactions.h"

BankTransactions bank;
CustomerDeletion customerDeletion;  // Assuming BankTransactions and CustomerDeletion are using the same vector

void displayMenu() {
    std::cout << "\n--- Bank Management System ---\n";
    std::cout << "1. Add Customer\n";
    std::cout << "2. Search Customer\n";
    std::cout << "3. Deposit Money\n";
    std::cout << "4. Withdraw Money\n";
    std::cout << "5. Delete Customer\n";
    std::cout << "6. Exit\n";
    std::cout << "Enter your choice: ";

}

// Utility function to get a valid integer input
int getValidIntInput(const std::string& prompt) {
    int value;
    while (true) {
        std::cout << prompt;
        std::cin >> value;
        if (std::cin.fail()) {
            std::cin.clear();           // Clear the error flag
            std::cin.ignore(INT_MAX, '\n');  // Discard any remaining characters in the buffer
            std::cout << "Invalid input. Please enter a number.\n";
        } else {
            break;  // Valid input received
        }
    }
    return value;
}

// Utility function to get a valid double input
double getValidDoubleInput(const std::string& prompt) {
    double value;
    while (true) {
        std::cout << prompt;
        std::cin >> value;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');
            std::cout << "Invalid input. Please enter a valid amount.\n";
        } else {
            break;
        }
    }
    return value;
}

void addCustomer() {
    int id = getValidIntInput("Enter customer ID: ");
    std::cin.ignore();  // Clear the buffer

    std::cout << "Enter full name: ";
    std::string name;
    getline(std::cin, name);

    std::cout << "Enter date of birth (YYYY-MM-DD): ";
    std::string dob;
    getline(std::cin, dob);

    std::cout << "Enter address: ";
    std::string address;
    getline(std::cin, address);

    std::cout << "Enter phone number: ";
    std::string phone;
    getline(std::cin, phone);

    std::cout << "Enter email: ";
    std::string email;
    getline(std::cin, email);

    bank.addCustomer(Customer(id, name, dob, address, phone, email));
    std::cout << "Customer added successfully.\n";
}

int main() {
    while (true) {
        if (bank.customers.empty()) {
            std::cout << "No customers found. Please add a customer first.\n";
            bank.addCustomer(Customer(1, "John Doe", "1990-01-01", "123 Street", "+1234567890", "john@example.com"));
            continue;
        }

        displayMenu();

        int choice;
        std::cin >> choice;
        int id;
        double amount;

        switch (choice) {
            case 1:  // Add Customer
                addCustomer();
                break;

            case 2:  // Search Customer
                std::cout << "Enter customer ID to search: ";
                std::cin >> id;
                searchAndDisplayCustomer(bank.customers, id);
                break;

            case 3:  // Deposit Money
                std::cout << "Enter customer ID for deposit: ";
                std::cin >> id;
                std::cout << "Enter amount to deposit: ";
                std::cin >> amount;
                bank.depositMoney(id, amount);
                break;

            case 4:  // Withdraw Money
                std::cout << "Enter customer ID for withdrawal: ";
                std::cin >> id;
                std::cout << "Enter amount to withdraw: ";
                std::cin >> amount;
                bank.withdrawMoney(id, amount);
                break;

            case 5:  // Delete Customer
                std::cout << "Enter customer ID to delete: ";
                std::cin >> id;
                customerDeletion.deleteCustomerById(id);
                break;

            case 6:  // Exit
                std::cout << "Exiting the system.\n";
                return 0;

            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}

