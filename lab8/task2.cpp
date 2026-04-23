#include <iostream>
using namespace std;

class Account
{
public:
    Account()
    {
    }

    virtual double calculateInterest() = 0;

    virtual ~Account()
    {
    }
};

class SavingsAccount : public Account
{

private:
    double balance, rate, time;

public:
    SavingsAccount(double b, double r, double t)
    {
        balance = b;
        rate = r;
        time = t;
    }

    double calculateInterest() override
    {
        return (balance * rate * time / 12.0);
    }
};

class CheckingAccount : public Account
{

private:
    double balance, rate, time, fee;

public:
    CheckingAccount(double b, double r, double t, double f)
    {
        balance = b;
        rate = r;
        time = t;
        fee = f;
    }

    double calculateInterest() override
    {
        return ((balance - fee) * rate * time / 12.0);
    }
};

int main()
{

    SavingsAccount acc1(5000, 0.03, 6);
    CheckingAccount acc2(3000, 0.015, 6, 10);

    cout << "\nSavings: \nInterest = " << acc1.calculateInterest();
    cout << "\n\nChecking: \nInterest = " << acc2.calculateInterest();

    return 0;
}