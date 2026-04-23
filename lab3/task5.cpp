#include <iostream>
using namespace std;

class Account
{
private:
    int account_no;
    double account_bal;
    int security_code;
    string name;

    void display()
    {

        if (verification())
        {
            cout << "Name: " << name << endl;
            cout << "\tAccount No: " << account_no << endl;
            cout << "\tAccount Balance: " << account_bal << endl;
        }
        else
        {

            cout << "Can not display info please Enter Correct Security Code." << endl;
        }
    }

    bool verification()
    {
        int pin;
        cout << "Account Holder: " << name << endl;
        cout << "Enter Security Pin: ";
        cin >> pin;
        return pin == security_code;
    }

public:
    Account()
    {
        account_no = 0101;
        account_bal = 5000;
        security_code = 1234;
        name = "Deepak Raj";
    }

    Account(string n, int acc_no, double bal, int pin)
    {
        name = n;
        account_no = acc_no;
        account_bal = bal;
        security_code = pin;
    }

    friend class Verifier;
};

class Verifier
{
public:
    void Display(Account &a)
    {
        a.display();
    }
};

int main()
{
    Account a;
    Verifier v;
    v.Display(a);

    return 0;
}