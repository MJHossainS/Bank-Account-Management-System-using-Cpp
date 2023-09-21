# Bank Management System

A simple and interactive bank management system implemented in C++.

## Features

### 1. **Add Customer**
- **Customer ID**: 
  - Must be an integer.
  - Unique for every customer. If an ID is provided that's already in use, the system will suggest an available ID.
  
- **Full Name**:
  - Should only contain letters.
  - Must start with a capital letter.
  - After any space, the next character should be capitalized.

- **Date of Birth**:
  - Format: `YYYY.MM.DD`.
  - The year should be four numerical digits, followed by a dot, then two numerical digits for the month, another dot, and finally two numerical digits for the day.

- **Phone Number**:
  - Should start with a "+".
  - All subsequent characters should be numerical digits.

- **Email**:
  - Must contain an "@" symbol.

### 2. **Search Customer**
- Search for a customer's details using their unique ID.

### 3. **Deposit Money**
- Deposit a specified amount to a customer's account using their unique ID.

### 4. **Withdraw Money**
- Withdraw a specified amount from a customer's account using their unique ID.
- Cannot withdraw more than the current balance.

### 5. **Delete Customer**
- Remove a customer from the system using their unique ID.

## Constraints
- Proper input validation is implemented to ensure data integrity.
- Informative prompts guide the user in case of invalid inputs.

