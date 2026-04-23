#include <iostream>
using namespace std;

class BankAccount
{
private:
    string name;
    int accountNumber;
    double balance;

public:
    
    BankAccount(string name, int accountNumber, double balance)
    {
        this->name = name;
        this->accountNumber = accountNumber;
        this->balance = balance;
    }

    
    void setName(string name)
    {
        this->name = name;
    }

    
    string getName()
    {
        return name;
    }

    
    void setAccountNumber(int accountNumber)
    {
        this->accountNumber = accountNumber;
    }


    int getAccountNumber()
    {
        return accountNumber;
    }

    
    void deposit(double amount)
    {
        if (amount > 0)
            this->balance += amount;
        else
            cout << "Invalid deposit amount." << endl;
    }


    void withdraw(double amount)
    {
        if (amount > 0 && amount <= balance)
            this->balance -= amount;
        else
            cout << "Insufficient balance or invalid amount." << endl;
    }

    void display()
    {
        cout << "Name: " << name << endl;
        cout << "Account #: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
    }
};


int main()
{
    BankAccount acc("Deepak Raj", 12345, 5000);

    acc.display();

    acc.deposit(1500);
    acc.withdraw(2000);

    cout << "\nAfter Transactions:\n";
    acc.display();

    return 0;
}
