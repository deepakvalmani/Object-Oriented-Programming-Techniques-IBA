#include <iostream>
using namespace std;

class BankAccount
{
private:
    double balance;

public:
    void SetBalance(double bal)
    {
        balance = bal;
    }

    double GetBalance()
    {
        return balance;
    }
};

class SavingsAccount : protected BankAccount
{

public:
    void addInterest(double rate)
    {
        double ExistingBal = GetBalance();
        SetBalance(ExistingBal * (rate + 1));
    }

    void SetBalance(double val)
    {
        BankAccount::SetBalance(val);
    }

    void displayBal() // this function is extra and displays the balance 
    {
        double bal = GetBalance();
        cout << "Balance = " << bal << endl;
    }
};

int main()
{
    SavingsAccount acc;
    acc.SetBalance(30000);
    acc.addInterest(0.08);
    //acc.GetBalance();
    // here get balance is not accessible as it is not in the protected mode in class SavingsAccount
    acc.displayBal();


    return 0;
}