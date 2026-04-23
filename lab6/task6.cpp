#include <iostream>
using namespace std;

class HospitalStaff
{
protected:
    int staffID;
    string name;

public:
    HospitalStaff(string n, int id)
    {
        staffID = id;
        name = n;
    }
    virtual string GetRole()
    {
        return "Hospital Staff";
    }
};

class Doctor : public HospitalStaff
{

private:
    string specialisation;

public:
    Doctor(string n, int id, string dep) : HospitalStaff(n, id)
    {
        specialisation = dep;
    }
    virtual string GetRole() override
    {
        return "Doctor";
    }

    void prescribe(string patientName)
    {
        cout << "Dr. " << name << " prescribed medication to " << patientName << endl;
    }
};

class Nurse : public HospitalStaff
{
private:
    string ward;

public:
    Nurse(string n, int id, string w) : HospitalStaff(n, id)
    {
        ward = w;
    }

    virtual string GetRole() override
    {
        return "Nurse";
    }
    void assist(string doctorName)
    {
        cout << "Nurse " << name << " Assisted " << doctorName << endl;
    }
};

class Administrator : protected HospitalStaff
{

private:
    string officeLocation;

public:
    Administrator(string n, int id, string location) : HospitalStaff(n, id)
    {
        officeLocation = location;
    }
    int GetstaffID()
    {
        return staffID;
    }
    string Getname()
    {
        return name;
    }

    void scheduleAppointment()
    {
        cout << "Appointment confirmed. " << endl;
    }
};

//getRole can not be called from main on administrator because class hospitalStaff is inherited in protected mode
//and in protected mode we can not access a member function from main function 

int main()
{
  
    Doctor d("Alice", 101, "Cardiology");
    cout << "Role: " << d.GetRole() << endl;
    d.prescribe("Bob");

    cout << endl;

    
    Nurse n("Charlie", 102, "Cardiology" );
    cout << "Role: " << n.GetRole() << endl;
    n.assist("Dr. Alice");

    cout << endl;

   
    Administrator a("David", 103, "Room 12");
    a.scheduleAppointment();
    cout << "Admin Staff ID: " << a.GetstaffID() << endl;
    cout << "Admin Name: " << a.Getname() << endl;

    return 0;
}