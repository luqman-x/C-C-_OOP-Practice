#include <iostream>
#include <string>

using namespace std;

class BankAccount
{
private:
    string accountName;
    int accountNumber;
    double balance;

public:
    // Constructor
    BankAccount(string name, int number, double initialBalance)
    {
        accountName = name;
        accountNumber = number;

        if (initialBalance >= 0)
        {
            balance = initialBalance;
        }
        else
        {
            balance = 0;
        }
    }

    // Deposit money
    void deposit(double amount)
    {
        if (amount > 0)
        {
            balance += amount;

            cout << "Deposit successful." << endl;
        }
        else
        {
            cout << "Invalid deposit amount." << endl;
        }
    }

    // Withdraw money
    void withdraw(double amount)
    {
        if (amount <= 0)
        {
            cout << "Invalid withdrawal amount." << endl;
        }
        else if (amount > balance)
        {
            cout << "Insufficient balance." << endl;
        }
        else
        {
            balance -= amount;

            cout << "Withdrawal successful." << endl;
        }
    }

    // Get balance
    double getBalance()
    {
        return balance;
    }

    // Transfer money
    void transfer(BankAccount &receiver, double amount)
    {
        if (amount <= 0)
        {
            cout << "Invalid transfer amount." << endl;
        }
        else if (amount > balance)
        {
            cout << "Insufficient balance for transfer." << endl;
        }
        else
        {
            balance -= amount;

            receiver.balance += amount;

            cout << "Transfer successful." << endl;
        }
    }

    // Display account information
    void displayAccount()
    {
        cout << "Account Name: " << accountName << endl;

        cout << "Account Number: " << accountNumber << endl;

        cout << "Balance: " << balance << endl;
    }
};

int main()
{
    BankAccount acc1("Ali", 1001, 1000);

    BankAccount acc2("Kwame", 1002, 500);

    cout << "Initial Accounts" << endl;

    acc1.displayAccount();

    cout << endl;

    acc2.displayAccount();

    cout << "\n---------------------\n"
         << endl;

    acc1.deposit(200);

    acc1.withdraw(100);

    cout << endl;

    acc1.displayAccount();

    cout << "\n---------------------\n"
         << endl;

    acc1.transfer(acc2, 500);

    cout << "\nAfter Transfer\n"
         << endl;

    acc1.displayAccount();

    cout << endl;

    acc2.displayAccount();

    return 0;
}