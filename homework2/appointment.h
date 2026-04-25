#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include <iostream>
#include <vector>
#include "hospital_staff.h"

using namespace std;

class appointment
{
public:
    Patient patient;
    Employee *employee;
    string date;
    string time_slot;

    appointment() {}

    appointment(Patient p,
                Employee *emp,
                string d,
                string t)
    {
        patient = p;
        employee = emp;
        date = d;
        time_slot = t;
    }
};

class appointment_book
{
public:
    vector<appointment> appointments;

    bool add_appointment(appointment app)
    {
        for (appointment &a : appointments)
        {
            if (a.employee->Id == app.employee->Id &&
                a.date == app.date &&
                a.time_slot == app.time_slot)
            {
                cout << "Slot already booked for this staff!\n";
                return false;
            }
        }

        appointments.push_back(app);
        cout << "Appointment Added\n";
        return true;
    }

    void cancel_appointment(appointment app)
    {
        int n = appointments.size();
        for (int i = 0; i < n; i++)
        {
            if (appointments[i].patient.Id == app.patient.Id &&
                appointments[i].date == app.date &&
                appointments[i].time_slot == app.time_slot)
            {
                appointments.erase(appointments.begin() + i);
                cout << "Appointment Cancelled\n";
                return;
            }
        }

        cout << "Appointment Not Found!\n";
    }

    void get_staff_appointments(int staffId, string date)
    {
        cout << "\nAppointments for Staff ID " << staffId << " on " << date << ":\n";

        for (auto &a : appointments)
        {
            if (a.employee->Id == staffId && a.date == date)
            {
                cout << "Patient ID: " << a.patient.Id
                     << " Time: " << a.time_slot << endl;
            }
        }
    }

    void get_patient_appointments(int patientId)
    {
        cout << "\nAppointments for Patient ID " << patientId << ":\n";

        for (auto &a : appointments)
        {
            if (a.patient.Id == patientId)
            {
                cout << "Staff ID: " << a.employee->Id
                     << " Date: " << a.date
                     << " Time: " << a.time_slot << endl;
            }
        }
    }
};

#endif
