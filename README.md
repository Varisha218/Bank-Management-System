# Banking System

A simple banking system built using C++. This console-based program allows users to create accounts, view account details, make transactions, and withdraw funds. Account information is stored in a file (`accountdetails.txt`) for persistence.

## Features

- **Account Creation**: Allows users to create a new account with a unique account number, balance, and password.
- **View Account Details**: Users can view their account details by entering their account number and password.
- **Transactions**: Allows users to transfer money from one account to another.
- **Withdrawal**: Allows users to withdraw money from their account.
- **PIN Verification**: For security, users are required to enter a correct PIN to access account details.

## File Structure

- **accountdetails.txt**: Stores account details persistently after each transaction or account creation.
- **main.cpp**: Contains all function definitions for creating accounts, transactions, withdrawals, and displaying account details.

## How to Use

1. **Run the program** and select an option:
   - Option 1: Create a new account.
   - Option 2: If you already have an account, you can:
      - **A**: View account balance
      - **B**: Make a transaction
      - **C**: Withdraw funds

2. **Follow the prompts** to enter account details, verify PIN, and perform transactions.

## Code Overview

### `account_details` and `transaction_details` Structures

- `account_details`: Stores user information, including `account_no`, `account_balance`, `password`, `fname` (first name), and `sname` (last name).
- `transaction_details`: Stores transaction details, including `from_account`, `to_account`, and `amount`.

### Main Functions

- **`acc_details`**: Displays the account balance for a specified account number.
- **`transaction`**: Transfers funds between accounts if sufficient balance exists.
- **`withdrawal`**: Withdraws an amount from the specified account.
- **`PIN`**: Verifies the user's PIN, allowing only three attempts for security.
- **`create_account`**: Creates a new account and saves it to `accountdetails.txt`.

## Sample Usage

1. **Account Creation**: Enter details such as first name, last name, account number, initial balance, and set a password.
2. **Transactions**: Enter your account number, the recipient's account number, and the amount to transfer.
3. **Withdrawals**: Enter your account number and the amount to withdraw if sufficient funds are available.

## Requirements

- C++ compiler (e.g., GCC)
- Basic knowledge of C++ and file handling
