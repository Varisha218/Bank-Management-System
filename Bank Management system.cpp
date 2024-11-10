#include <iostream>
#include <string>
#include<fstream>
using namespace std;

struct account_details {
    long account_no;
    int account_balance;
    long password;
    string fname;
    string sname;
};

struct transaction_details {
    long from_account;
    long to_account;
    int amount;
};

// Function declarations
void acc_details(account_details customer[], int numCustomers);
void transaction(account_details customer[], int numCustomers);
void withdrawal(account_details customer[], int numCustomers);
int PIN(long acc, int pass);
int create_account(account_details customer[],int &numCustomers);

int main() {
    int opt;
    char select;
    const int max=20;
	    account_details customer[max] = {
        {912, 30000, 8765, "Ali", "Ahmed"},
        {219, 10000, 8921, "Fazal", "Rahim"},
        {432, 40000, 9876, "Lily", "Rose Depp"},
        {897, 50000, 3451, "Monica", "Jake"},
        {892, 60000, 3216, "Aliyan", "Akmal"},
        {431, 70000, 7654, "Raheem", "Khan"},
        {568, 90000, 9076, "Selena", "Gomez"},
        {234, 56000, 4567, "Christopher", "Harry"},
        {654, 100000, 2365, "Romina", "Ejaz"},
        {123, 90000, 8764, "Mahira", "Ali"}
    };
    ofstream obj;
    obj.open("accountdetails.txt", ios::app);
    for(int i = 0; i < max; i++) {
    obj << customer[i].account_no << " "
        << customer[i].account_balance << " "
        << customer[i].password << " "
        << customer[i].fname << " "
        << customer[i].sname << endl;
}
obj.close();

    int numCustomers = 10;

    for (int i = 0; i < 120; i++) {
        cout << "-";
    }
    cout << "\nHi Welcome to our bank!";
    cout << "\nEnter 1 if you want to open an account";
    cout << "\nEnter 2, if you already have an account:";
    cin >> opt;

    if (opt == 1) {
        create_account(customer,numCustomers);
    } else if (opt == 2) {
        cout << "\nSelect an option";
        cout << "\nA. Account Balance";
        cout << "\nB. Transaction";
        cout << "\nC. Withdrawal" << endl;
        cin >> select;

        switch (select) {
            case 'A':
                acc_details(customer, numCustomers);
                break;
            case 'B':
                transaction(customer, numCustomers);
                break;
            case 'C':
                withdrawal(customer, numCustomers);
                break;
            default:
                cout << "Invalid choice";
                break;
        }
    }
        else {
        cout << "Invalid choice:";
    }
    return 0;
}

int create_account(account_details customer[], int &numCustomers) {
    if (numCustomers<20) {
        cout << "Enter your first name:";
        cin >> customer[numCustomers].fname;
        cout << "Enter your last name:";
        cin >> customer[numCustomers].sname;
        cout << "Enter account number:";
        cin >> customer[numCustomers].account_no;
        cout << "Enter initial account balance:";
        cin >> customer[numCustomers].account_balance;
        cout << "Set a password:";
        cin >> customer[numCustomers].password;
        cout << "Account created successfully!" << endl;

        ofstream obj("accountdetails.txt", ios::app);
        if (obj.is_open()) {
            obj << customer[numCustomers].account_no << " "
                << customer[numCustomers].account_balance << " "
                << customer[numCustomers].password << " "
                << customer[numCustomers].fname << " "
                << customer[numCustomers].sname << endl;
            obj.close();
        } else {
            cout << "Error opening file for writing." << endl;
        }

        numCustomers++;

        return numCustomers;
    } else {
        cout << "Maximum number of customers reached!" << endl;
        return numCustomers;
    }
}



void acc_details(account_details customer[], int numCustomers) {
    long acc_no;
    int pin;

    cout << "Enter your account number:";
    cin >> acc_no;

    int index = -1;
    for (int i = 0; i < numCustomers; i++) {
        if (customer[i].account_no == acc_no) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        pin = PIN(acc_no, customer[index].password);

        if (pin != -1) {
        	cout<<"Welcome!"<<endl;
            cout << "Account Holder: " << customer[index].fname << " " << customer[index].sname << endl;
            cout << "Account no: " << customer[index].account_no << endl;
            cout << "Account balance: " << customer[index].account_balance << endl;
        } else {
            cout << "Invalid PIN." << endl;
        }
    } else {
        cout << "No account found" << endl;
    }
}


void transaction(account_details customer[], int numCustomers) {
    long from_account, to_account;
    int transacmoney;

    cout << "Enter your account number: ";
    cin >> from_account;

    int fromIndex = -1;
    for (int i = 0; i < numCustomers; ++i) {
        if (customer[i].account_no == from_account) {
            fromIndex = i;
            break;
        }
    }

    if (fromIndex != -1) {
        cout << "Enter the account number to whom you want to transact: ";
        cin >> to_account;

        int toIndex = -1;
        for (int i = 0; i < numCustomers; ++i) {
            if (customer[i].account_no == to_account) {
                toIndex = i;
                break;
            }
        }

        if (toIndex != -1) {
            cout << "Enter the amount you want to transact: ";
            cin >> transacmoney;

            if (customer[fromIndex].account_balance >= transacmoney) {
                customer[fromIndex].account_balance -= transacmoney;
                customer[toIndex].account_balance += transacmoney;

                cout << "Transaction successful!" << endl;
                cout << "New balance for account " << customer[fromIndex].account_no << ": " << customer[fromIndex].account_balance << endl;
                cout << "New balance for account " << customer[toIndex].account_no << ": " << customer[toIndex].account_balance << endl;
            } else {
                cout << "Insufficient funds for the transaction." << endl;
            }
        } else {
            cout << "Destination account not found." << endl;
        }
    } else {
        cout << "Source account not found." << endl;
    }
}

void withdrawal(account_details customer[], int numCustomers) {
    long id;
    int afterwithdrawal;

    cout << "Enter your account number: ";
    cin >> id;

    int index = -1;
    for (int i = 0; i < numCustomers; ++i) {
        if (customer[i].account_no == id) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        cout << "Enter the amount you want to withdraw: ";
        cin >> afterwithdrawal;

        if (customer[index].account_balance >= afterwithdrawal) {
            customer[index].account_balance -= afterwithdrawal;

            cout << "Withdrawal successful" << endl;
            cout << "New balance for account " << customer[index].account_no << ": " << customer[index].account_balance << endl;
        } else {
            cout << "Insufficient funds for withdrawal." << endl;
        }
    } else {
        cout << "Account not found." << endl;
    }
}

int PIN(long acc, int pass) {
    int pin;
    int i = 3;

    do {
        cout << "Enter a password:";
        cin >> pin;
        if (pin == pass) {
            cout << "\nWelcome";
            break;
        } else {
            cout << "Invalid Pass, Remaining attempts " << i << endl;
            i--;
        }
        cout << endl;
    } while (i >= 0);

    if (i < 0) {
        cout << "Too many incorrect attempts. Access denied." << endl;
        return -1; 
    }

    return pin;
}
