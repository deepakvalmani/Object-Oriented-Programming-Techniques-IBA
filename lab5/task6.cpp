#include <iostream>
#include <limits>
using namespace std;

class Person
{
protected:
    int emp_id;

public:
    virtual void getData()
    {
        cout << "Enter Employee ID: ";
        cin >> emp_id;

        while (cin.fail() || emp_id <= 0)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid ID. Enter again: ";
            cin >> emp_id;
        }
    }

    virtual void displayData()
    {
        cout << "Employee ID: " << emp_id << endl;
    }

    virtual ~Person() {}
};

class Admin : public Person
{
    string name;
    double monthly_income;

public:
    void getData() override
    {
        Person::getData();

        cout << "Enter Name: ";
        cin >> name;

        while (name.empty())
        {
            cout << "Invalid name. Enter again: ";
            cin >> name;
        }

        cout << "Enter Monthly Income: ";
        cin >> monthly_income;

        while (cin.fail() || monthly_income <= 0)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Income must be positive. Enter again: ";
            cin >> monthly_income;
        }
    }

    double bonus(bool bestEmployee = false)
    {
        double totalBonus = monthly_income * 0.05;
        if (bestEmployee)
            totalBonus += monthly_income * 0.10;
        return totalBonus;
    }

    void displayData() override
    {
        Person::displayData();
        cout << "Name: " << name << endl;
        cout << "Monthly Income: " << monthly_income << endl;
        cout << "Bonus: " << bonus() << endl;
    }
};

class Accounts : public Person
{
    string name;
    double monthly_income;

public:
    void getData() override
    {
        Person::getData();

        cout << "Enter Name: ";
        cin >> name;

        while (name.empty())
        {
            cout << "Invalid name. Enter again: ";
            cin >> name;
        }

        cout << "Enter Monthly Income: ";
        cin >> monthly_income;

        while (cin.fail() || monthly_income <= 0)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Income must be positive. Enter again: ";
            cin >> monthly_income;
        }
    }

    double bonus(bool bestEmployee = false)
    {
        double totalBonus = monthly_income * 0.05;
        if (bestEmployee)
            totalBonus += monthly_income * 0.10;
        return totalBonus;
    }

    void displayData() override
    {
        Person::displayData();
        cout << "Name: " << name << endl;
        cout << "Monthly Income: " << monthly_income << endl;
        cout << "Bonus: " << bonus() << endl;
    }
};

int main()
{
    int choice;

    cout << "===== Bonus Calculator =====" << endl;
    cout << "1. Admin" << endl;
    cout << "2. Accounts" << endl;
    cout << "Enter Department: ";
    cin >> choice;

    if (choice == 1)
    {
        Admin a;
        a.getData();

        char best;
        cout << "Is this employee Best Employee of the Month? (y/n): ";
        cin >> best;

        cout << "\n--- Employee Details ---" << endl;
        a.displayData();

        if (best == 'y' || best == 'Y')
            cout << "Special Bonus: " << a.bonus(true) << endl;
    }
    else if (choice == 2)
    {
        Accounts acc;
        acc.getData();

        char best;
        cout << "Is this employee Best Employee of the Month? (y/n): ";
        cin >> best;

        cout << "\n--- Employee Details ---" << endl;
        acc.displayData();

        if (best == 'y' || best == 'Y')
            cout << "Special Bonus: " << acc.bonus(true) << endl;
    }
    else
    {
        cout << "Invalid Choice!" << endl;
    }

    return 0;
}