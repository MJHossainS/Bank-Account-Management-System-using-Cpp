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
            std::cin.ignore(INT_MAX, '\n');  // Also clear any extra characters left in the buffer
            break;  // Valid input received
        }
    }
    return value;
}

// Utility function to check if an ID is already taken
bool isIdTaken(int id) {
    for (const Customer& customer : bank.getCustomers()) {
        if (customer.getCustomerId() == id) {
            return true;
        }
    }
    return false;
}


// function to get the next available ID
int getNextAvailableId() {
    int nextId = 1;  // Start from 1
    while (isIdTaken(nextId)) {
        nextId++;
    }
    return nextId;
}




bool isValidName(const std::string& name) {
    if (!isupper(name[0])) {  // First character should be uppercase
        return false;
    }
    for (size_t i = 1; i < name.size(); ++i) {
        if (name[i] == ' ') {
            if (i + 1 == name.size() || !isupper(name[i + 1])) {  // Next character after space should be uppercase
                return false;
            }
        } else if (!isalpha(name[i])) {  // All characters should be alphabetic
            return false;
        }
    }
    return true;
}


// Utility function to validate the date of birth format
bool isValidDOBFormat(const std::string& dob) {
    if (dob.size() != 10) return false;  // Check for length

    for (size_t i = 0; i < dob.size(); ++i) {
        if (i == 4 || i == 7) {  // Positions for '.'
            if (dob[i] != '.') return false;
        } else if (!isdigit(dob[i])) {  // Every other position should be a digit
            return false;
        }
    }
    return true;
}


void addCustomer() {


    int id = getValidIntInput("Enter customer ID: ");
    while (isIdTaken(id)) {
        std::cout << "This ID is already taken by another customer. ";
        id = getNextAvailableId();
        std::cout << "Suggested ID: " << id << ". Do you want to use this ID? (y/n): ";
        char choice;
        std::cin >> choice;
        std::cin.ignore();  // Clear the newline character from the buffer
        if (choice == 'y' || choice == 'Y') {
            break;
        } else {
            id = getValidIntInput("Enter another customer ID: ");
        }
    }



    std::cout << "Enter full name: ";
    std::string name;
    getline(std::cin, name);
    while (!isValidName(name)) {
        std::cout << "Invalid name format. Name should contain only letters, start with a capital letter, and any character after a space should be capital. Enter again: ";
        getline(std::cin, name);
    }

    std::cout << "Enter date of birth (YYYY.MM.DD): ";
    std::string dob;
    getline(std::cin, dob);
    while (!isValidDOBFormat(dob)) {
        std::cout << "Invalid date format. Please enter the date in the format YYYY.MM.DD: ";
        getline(std::cin, dob);
    }

    std::cout << "Enter address: ";
    std::string address;
    getline(std::cin, address);


    std::cout << "Enter phone number: ";
    std::string phone;
    getline(std::cin, phone);
    while (phone[0] != '+' || !std::all_of(phone.begin() + 1, phone.end(), ::isdigit)) {
        std::cout << "Invalid phone number format. It should start with '+' and followed by numerical digits. Enter again: ";
        getline(std::cin, phone);
    }

    std::cout << "Enter email: ";
    std::string email;
    getline(std::cin, email);
    while (email.find("@") == std::string::npos) {
        std::cout << "The email is not correct. Add a valid email: ";
        getline(std::cin, email);
    }

    bank.addCustomer(Customer(id, name, dob, address, phone, email));
    std::cout << "Customer added successfully.\n";
}

int main() {
    while (true) {


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
                searchAndDisplayCustomer(bank.getCustomers(), id);
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

