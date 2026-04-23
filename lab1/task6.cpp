#include <iostream>
using namespace std;

class Employee
{
private:
    string f_name;
    string l_name;
    double salary;

public:
    // Constructor
    Employee(string f, string l, double s)
    {
        f_name = f;
        l_name = l;
        salary = (s < 0.0) ? 0.0 : s;
    }

    double yearlySalary() const
    {
        return salary * 12;
    }

    void giveRaise(double percent)
    {
        salary += salary * percent / 100;
    }

    double getSalary() const
    {
        return salary;
    }
};

int main()
{
    Employee e1("Deepak", "Raj", 20000);
    Employee e2("Jiya", "Turshani", 30000);

    cout << "Yearly salary e1 = " << e1.yearlySalary() << endl;
    cout << "Yearly salary e2 = " << e2.yearlySalary() << endl;

    cout << "Raised the salary by 10%" << endl;
    e1.giveRaise(10);
    e2.giveRaise(10);

    cout << "Yearly salary e1 = " << e1.yearlySalary() << endl;
    cout << "Yearly salary e2 = " << e2.yearlySalary() << endl;

    return 0;
}
