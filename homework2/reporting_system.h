#ifndef REPORTING_SYSTEM_H
#define REPORTING_SYSTEM_H

#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <functional>
#include <iostream>
#include "appointment.h"
#include "patient.h"
#include "hospital_staff.h"

class ReportingSystem
{
public:
    // --- 1. PATIENT FILTERING ---
    // Filters patients by ward, diagnosis keyword, or date range
    static vector<Patient> filter_patients(const vector<Patient> &patients,
                                           function<bool(const Patient &)> predicate)
    {
        vector<Patient> results;
        // Using std::copy_if instead of a manual loop with if/else
        copy_if(patients.begin(), patients.end(), back_inserter(results), predicate);
        return results;
    }

    // --- 2. PATIENT SORTING ---
    // Sorts patients by surname, admission date, or total bill
    static void sort_patients(vector<Patient> &patients,
                              function<bool(const Patient &, const Patient &)> comparator)
    {
        // std::sort handles the logic internally
        sort(patients.begin(), patients.end(), comparator);
    }

    // --- 3. STAFF FILTERING ---
    // Filters staff by department or role (using dynamic_cast)
    static vector<Employee *> filter_staff(const vector<Employee *> &staff,
                                           function<bool(Employee *)> predicate)
    {
        vector<Employee *> results;
        copy_if(staff.begin(), staff.end(), back_inserter(results), predicate);
        return results;
    }

    // --- 4. WARD REVENUE ---
    // Returns total revenue from all discharged patients in a specific ward
    static double get_ward_revenue(const vector<Patient> &patients, string ward_name)
    {
        return accumulate(patients.begin(), patients.end(), 0.0,
                          [&](double total, const Patient &p)
                          {
                              if (p.Is_discharged && p.ward == ward_name)
                              {
                                  // Must cast to non-const to call generate_bill() as defined
                                  return total + const_cast<Patient &>(p).generate_bill().total();
                              }
                              return total;
                          });
    }

    // --- 5. STAFF TREATMENT HISTORY ---
    // Returns all patients treated by a specific staff member
    static vector<Patient> get_patients_by_staff(const vector<Patient> &patients, string staff_name)
    {
        vector<Patient> treated;
        copy_if(patients.begin(), patients.end(), back_inserter(treated),
                [&](const Patient &p)
                {
                    // Uses std::any_of to search the treatment vector
                    return any_of(p.treatments.begin(), p.treatments.end(),
                                  [&](const treatmeant &t)
                                  { return t.staff_name == staff_name; });
                });
        return treated;
    }
};

class Ward
{
public:
    string name;
    int capacity; // number of beds
    vector<Patient> patients;

    Ward() {};
    Ward(
        string n, int c)
    {
        name = n;
        capacity = c;
    }

    void set_name(string n)
    {
        name = n;
    }
    void set_capacity(int c)
    {
        capacity = c;
    }

    int occupancyy()
    {
        return patients.size();
    }
    int get_capacity() { return capacity; }

    virtual void add_patient(Patient p)
    {
        int n = patients.size();
        if (n < capacity)
        {
            patients.push_back(p);
        }
        else
        {
            cout << "Capacity full!" << endl;
        }
    }

    void remove_patient(Patient p)
    {
        int n = patients.size();
        for (int i = 0; i < n; i++)
        {
            if (patients[i].Id == p.Id)
            {
                patients.erase(patients.begin() + i);
                break;
            }
        }
    }

    bool operator<(const Ward &other) const
    {
        return patients.size() < other.patients.size();
    }

    bool operator>(const Ward &other) const
    {
        return patients.size() > other.patients.size();
    }

    bool operator==(const Ward &other) const
    {
        return patients.size() == other.patients.size();
    }
    double occupancy_percentage() const
    {
        if (capacity == 0)
            return 0.0;
        return (static_cast<double>(patients.size()) / capacity) * 100.0;
    }
};

class ICU_ward : public Ward
{
public:
    ICU_ward() {};

    void add_patient(Patient p) override
    {
        if (p.diagnosis == "critical" || p.diagnosis == "Critical")
        {
            int n = patients.size();
            if (n < capacity)
            {
                patients.push_back(p);
            }
            else
            {
                cout << "Capacity full!" << endl;
            }
        }
        else
        {
            cout << "Can not add Patient.\n";
        }
    }
};
class Surgical_ward : public Ward
{
public:
    Surgical_ward() {};
    void add_patient(Patient p) override
    {
        if (p.has_surgery)
        {
            int n = patients.size();
            if (n < capacity)
                patients.push_back(p);
            else
            {
                cout << "Capacity full!" << endl;
            }
        }
        else
        {
            cout << "Can not add Patient.";
        }
    }
};

#endif