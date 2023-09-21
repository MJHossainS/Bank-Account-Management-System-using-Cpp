#ifndef CREATE_CUSTOMER_H
#define CREATE_CUSTOMER_H

#include <string>

class Customer {
private:
    int customer_id;

public:
    std::string full_name;
    std::string date_of_birth;  // Format: YYYY-MM-DD
    std::string address;
    std::string phone_number;
    std::string email;
    double account_balance;

    Customer(int id, const std::string& name, const std::string& dob, const std::string& addr,
             const std::string& phone, const std::string& mail)
        : customer_id(id), full_name(name), date_of_birth(dob), address(addr),
          phone_number(phone), email(mail), account_balance(0.0) {}

    int getCustomerId() const {
        return customer_id;
    }
};

#endif  // CREATE_CUSTOMER_H
