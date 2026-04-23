#ifndef PERSON_H
#define PERSON_H

#include <iostream>
using namespace std;

class Person
{
public:
    string name;
    string date_of_birth;
    int Id;
    string phone_number;

    // Default Constructor
    Person()
    {
    }
    // Parameterised Constructor
    Person(
        string name,
        string date_of_birth,
        int Id,
        string phone_number)
    {
        this->name = name;
        this->date_of_birth = date_of_birth;
        this->Id = Id;
        this->phone_number = phone_number;
    }

    // setter and getter functions
    void set_name(string name)
    {
        this->name = name;
    }
    void set_date_of_birth(string date_of_birth)
    {
        this->date_of_birth = date_of_birth;
    }
    void set_Id(int Id)
    {
        this->Id = Id;
    }
    void set_phone_number(string phone_number)
    {
        this->phone_number = phone_number;
    }

    string get_name()
    {
        return this->name;
    }
    string get_date_of_birth()
    {
        return this->date_of_birth;
    }
    int get_Id()
    {
        return this->Id;
    }
    string get_phone_number()
    {
        return this->phone_number;
    }

    virtual void display_info()
    {
        cout << "Name : " << name
             << "\nId: " << Id
             << "\nDate of birth: " << date_of_birth
             << "\nPhone Number: " << phone_number;
    }

   
    
};

#endif 
