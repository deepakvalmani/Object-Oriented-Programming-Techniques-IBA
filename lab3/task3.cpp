#include <iostream>
using namespace std;

class Account
{
private:
    int account_no;
    double account_bal;
    int security_code;
    string name;

public:
    Account()
    {
        account_no = 101;
        account_bal = 5000;
        security_code = 1234;
        name = "Deepak Raj";
    }

    void initialize(int accNo, double bal, int pin, string name)
    {
        account_no = accNo;
        account_bal = bal;
        security_code = pin;
        this->name = name;
    }

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
};
int main()
{
    Account a;
    a.display();

    return 0;
}