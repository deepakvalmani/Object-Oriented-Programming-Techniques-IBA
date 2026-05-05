#ifndef PATIENT_H
#define PATIENT_H

#include <iostream>
#include <vector>
#include "billing.h"
#include <algorithm> 
#include <numeric>   
#include <functional> 
#include <iterator>  
#include "person.h"

using namespace std;

class treatmeant
{

public:
    string t_name;
    double cost;
    string staff_name;

    // constructor
    treatmeant() {};
    treatmeant(
        string t_name,
        double cost,
        string staff_name)
    {
        this->t_name = t_name;
        this->cost = cost;
        this->staff_name = staff_name;
    }

    // geter and seter functions
    void set_t_name(string name)
    {
        t_name = name;
    }
    void set_cost(double c)
    {
        cost = c;
    }
    void set_staff_name(string name)
    {
        staff_name = name;
    }

    string get_t_name()
    {
        return t_name;
    }
    double get_cost()
    {
        return cost;
    }
    string get_staff_name()
    {
        return staff_name;
    }
};

class Patient : public Person{

public:
    string diagnosis;
    string admission_date;
    string ward;
    vector<treatmeant> treatments;
    bool Is_archive;
    bool Is_discharged;
    bool has_surgery;
    int days_admitted;
    double ward_daily_rate;
    string sur_name;

    Patient() {};
    Patient(
        string diagnosis,
        string admission_date,
        string ward,
        string name,
        string date_of_birth,
        int Id,
        string phone_number,
        int days,
        double w_fee,
        string s_name) : Person(name, date_of_birth, Id, phone_number)
    {
        this->diagnosis = diagnosis;
        this->admission_date = admission_date;
        this->ward = ward;
        Is_archive = false;
        Is_discharged = false;
        has_surgery = false;
        days_admitted = days;
        ward_daily_rate = w_fee;
        sur_name = s_name;
    }
    void set_days_admitted(int d) { days_admitted = d; };
    void set_ward_rate(double rate) { ward_daily_rate = rate; };

    void set_has_surgery(bool val)
    {
        has_surgery = val;
    }

    void set_surname(string n)
    {
        sur_name = n;
    }

    string get_surname()
    {
        return sur_name;
    }
    void set_diagnosis(string d)
    {
        diagnosis = d;
    }
    void set_ward(string w)
    {
        ward = w;
    }
    void set_admission_date(string a_date)
    {
        admission_date = a_date;
    }
    void add_treatment(treatmeant t)
    {
        treatments.push_back(t);
    }
    string get_diagnosis()
    {
        return diagnosis;
    }
    string get_admission_date()
    {
        return admission_date;
    }

    string get_ward()
    {
        return ward;
    }

    bool get_has_surgery()
    {
        return has_surgery;
    }
    void archive()
    {
        Is_archive = true;
    }

    void discharge()
    {
        Is_discharged = true;
        Is_archive = true;
        cout << "Pateint has been discharged!\n";
        Bill b = generate_bill();
        cout << b;
    }

    void display_info() override
    {
        Person::display_info();
        cout << "\ndiagnosis: " << diagnosis
             << "\nadmission date: " << admission_date
             << "\nward: " << ward
             << "\n";
    }
    Bill generate_bill() const
    {
        Bill b;
        for (const treatmeant &val : treatments)
        {
            b.treatment_cost += val.cost;
        }
        b.ward_fee = days_admitted * ward_daily_rate;

        return b;
    }
};

class Hospital
{
public:
    vector<Patient> live_records;
    vector<Patient> archive;

    void admit(Patient p)
    {
        live_records.push_back(p);
    }

    void discharge(int patientId)
    {
        auto it = find_if(live_records.begin(), live_records.end(),
                          [patientId](const Patient &p)
                          { return p.Id == patientId; });

        if (it != live_records.end())
        {
            it->discharge();

            archive.push_back(std::move(*it));

            live_records.erase(it);
        }
    }

    vector<Patient> filterPatients(function<bool(const Patient &)> predicate)
    {
        vector<Patient> results;
        // std::copy_if handles the loop and the 'if' logic internally
        copy_if(live_records.begin(), live_records.end(), back_inserter(results), predicate);
        return results;
    }

    void sortPatients(function<bool(const Patient &, const Patient &)> comparator)
    {
        sort(live_records.begin(), live_records.end(), comparator);
    }

    bool isAdmitted(int id)
    {
        return any_of(live_records.begin(), live_records.end(),
                      [id](const Patient &p)
                      { return p.Id == id; });
    }

    bool isArchived(int id)
    {
        return any_of(archive.begin(), archive.end(),
                      [id](const Patient &p)
                      { return p.Id == id; });
    }

    double wardRevenue(string wardName)
    {
        return accumulate(archive.begin(), archive.end(), 0.0,
                          [&](double total, const Patient &p)
                          {
                              if (p.ward == wardName)
                              {
                                  return total + const_cast<Patient &>(p).generate_bill().total();
                              }
                              return total;
                          });
    }
};

#endif