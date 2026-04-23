#include <iostream>
using namespace std;

class Person
{
protected:
    string name;
    string CNIC;

public:
    Person(string name, string cnic)
    {
        this->name = name;
        CNIC = cnic;
    }

    virtual void DisplayInfo()
    {
        cout << "Name: " << name << endl;
        cout << "CNIC: " << CNIC << endl;
    }
};

class Student : public Person
{

private:
    string rollNumber;
    double GPA;

public:
    Student(string name, string cnic, string rollNumber, double gpa) : Person(name, cnic)
    {
        this->rollNumber = rollNumber;
        GPA = gpa;
    }

    void DisplayInfo() override
    {
        cout << "Name: " << name << endl;
        cout << "CNIC: " << CNIC << endl;
        cout << "roll No: " << rollNumber << endl;
        cout << "GPA: " << GPA << endl;
    }
};

class Lecturer : public Person
{
private:
    string EmpId;
    string department;

public:
    Lecturer(string name, string cnic, string id, string dept) : Person(name, cnic)
    {
        EmpId = id;
        department = dept;
    }

    void DisplayInfo() override
    {
        cout << "Name: " << name << endl;
        cout << "CNIC: " << CNIC << endl;
        cout << "Emp ID: " << EmpId << endl;
        cout << "Department: " << department << endl;
    }
};
int main()
{

    Student s("Ali Khan", "35202-1234567-1", "FA21-BCS-001", 3.75);

    Lecturer l("Dr. Ahmed", "35202-7654321-9", "EMP1001", "Computer Science");

    cout << "Student Information" << endl;
    s.DisplayInfo();

    cout << "\nLecturer Information" << endl;
    l.DisplayInfo();

    return 0;
}