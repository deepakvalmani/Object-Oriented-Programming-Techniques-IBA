#ifndef HOSPITAL_STAFF_H
#define HOSPITAL_STAFF_H

#include <iostream>
#include "patient.h"
#include "person.h"

using namespace std;

class Employee : public Person
{

public:
    double salary;
    string department;

    Employee() {}
    Employee(
        string name,
        string date_of_birth,
        int Id,
        string phone_number,
        double salary,
        string department) : Person(name, date_of_birth, Id, phone_number)
    {
        this->salary = salary;
        this->department = department;
    }

    void set_salary(double sal)
    {
        salary = sal;
    }
    void set_department(string dpt)
    {
        department = dpt;
    }

    double get_salary()
    {
        return salary;
    }
    string get_department()
    {
        return department;
    }

    void display_info() override
    {
        Person::display_info();
        cout << "\nSalary: " << salary
             << "\nDepartment: " << department;
    }

    virtual double calculate_bill(double x) {return x;};
    virtual double get_fee() = 0;

};

class general_practitioner : public Employee
{
public:
    double fee;

    general_practitioner() {}
    general_practitioner(
        string n,
        string d,
        int Id,
        string ph,
        double salary,
        string dpt,
        double fee) : Employee(n, d, Id, ph, salary, dpt)
    {
        this->fee = fee;
    }

    void set_fee(double f)
    {
        fee = f;
    }

    double get_fee() override
    {
        return fee;
    }
    void display_info() override
    {
        Employee::display_info();
        cout << "\nFee: " << fee;
    }

    void consult_patient(Patient &patient)
    {
        cout << "\nDr. " << name << " is consulting patient " << patient.get_name();
    }

    double calculate_bill(double hours) override
    {
        return (fee * hours);
    }

    void write_prescription(Patient &patient, string medication)
    {
        cout << "\nDr. " << name << " wrote a prescription for " << medication
             << " for patient " << patient.get_name() << ".";
    }
};

class Surgeon : public Employee
{
public:
    string specialization;
    double fee; // billing rate per operation

    Surgeon() {}
    Surgeon(
        string n,
        string d,
        int Id,
        string ph,
        double salary,
        string dpt,
        double fee,
        string spec) : Employee(n, d, Id, ph, salary, dpt)
    {
        this->fee = fee;
        this->specialization = spec;
    }
    void set_fee(double f)
    {
        fee = f;
    }
    void set_specialization(string s)
    {
        specialization = s;
    }
    string get_specialization()
    {
        return specialization;
    }
    double get_fee() override
    {
        return fee;
    }
    void display_info() override
    {
        Employee::display_info();
        cout << "\nspecialization: " << specialization
             << "\nFee: " << fee;
    }
    void perform_operation()
    {
        cout << "Dr. " << name << " is performing a "
             << specialization << " operation.\n";
    }
    double calculate_bill(double opt) override
    {
        return (fee * opt);
    }
};

class Nurse : public Employee
{
public:
    double fee;
    string ward;

    Nurse() {};
    Nurse(string n,
          string d,
          int Id,
          string ph,
          double salary,
          string dpt,
          double fee,
          string ward) : Employee(n, d, Id, ph, salary, dpt)
    {
        this->fee = fee;
        this->ward = ward;
    }
    void set_ward(string w)
    {
        ward = w;
    }
    void set_fee(double f)
    {
        fee = f;
    }
    double get_fee() override
    {
        return fee;
    }
    string get_ward()
    {
        return ward;
    }
    void display_info() override
    {
        Employee::display_info();
        cout << "\nFee: " << fee
             << "\nWard: " << ward;
    }

    double calculate_bill(double hours) override
    {
        return (fee * hours);
    }
};

#endif