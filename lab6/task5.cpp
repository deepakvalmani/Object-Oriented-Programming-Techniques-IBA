#include <iostream>
using namespace std;

class Employee
{
protected:
    int empId;
    double baseSalalry;

public:
    Employee(int id, double sal)
    {

        empId = id;
        baseSalalry = sal;
    }

    virtual void display()
    {
        cout << "Employee Id: " << empId << endl;
        cout << "Salary: " << baseSalalry << endl;
        cout << "Bonus: " << baseSalalry * (0.05) << endl;
    }
};

class Manager : public Employee
{

private:
    string deptartment;

public:
    Manager(int id, double sal, string dep) : Employee(id, sal)
    {
        deptartment = dep;
    }

    void display() override
    {
        cout << "Employee Id: " << empId << endl;
        cout << "Salary: " << baseSalalry << endl;
        cout << "Department: " << deptartment << endl;
        cout << "Bonus: " << baseSalalry * (0.10) << endl;
    }

    string GetDept()
    {
        return deptartment;
    }
};

class RegionalDirector : public Manager
{
private:
    string region;

public:
    RegionalDirector(int id, double sal, string dep, string region) : Manager(id, sal, dep)
    {

        this->region = region;
    }

    void display() override
    {
        cout << "Employee Id: " << empId << endl;
        cout << "Salary: " << baseSalalry << endl;
        cout << "Department: " << GetDept() << endl;
        cout << "Region :" << region << endl;
        cout << "Bonus: " << baseSalalry * (0.15) << endl;
    }
};

int main()
{

    Employee e(101, 50000);

    Manager m(102, 70000, "HR");

    RegionalDirector r(103, 90000, "Sales", "North");

    cout << " Employee " << endl;
    e.display();

    cout << "\nManager" << endl;
    m.display();

    cout << "\nRegional Director" << endl;
    r.display();

    return 0;
}