#include <iostream>
#include <vector>
#include <cassert>
#include "reporting_system.h"
#include "person.h"
#include "patient.h"
#include "billing.h"
#include "hospital_staff.h"
#include "appointment.h"

void check(bool condition, string test_name)
{
    if (condition)
    {
        cout << test_name << " | PASS" << endl;
    }
    else
    {
        cout << test_name << " | FAIL" << endl;
    }
}

using namespace std;

int main()
{
    // -----------------------------------------------------Test Case 01-----------------------------------------------------
    //  General Practitioner
    general_practitioner gp1("Dr. Deepak", "1980-05-12", 101, "555-0101", 80000, "Internal Med", 150.0);
    //  Surgeon
    Surgeon surgeon1("Dr. Ali Hasan", "1975-08-20", 102, "555-0202", 150000, "Surgery", 2000.0, "Cardiothoracic");
    //  Nurse
    Nurse nurse1("Nurse samiya", "1990-02-14", 103, "555-0303", 50000, "Nursing", 50.0, "General Ward A");
    //  Patient
    Patient patient1("Pneumonia", "2023-10-01", "General Ward A", "Haider ", "1995-12-25", 501, "555-9999", 3, 200.0, "Doe");

    cout << "\n================================================Hospital Management System================================================\n";
    cout << "\n-----------------------------------------------------Test Case 01-----------------------------------------------------\n"
         << endl;

    vector<Person *> people = {&gp1, &surgeon1, &nurse1, &patient1};

    for (auto *p : people)
    {
        p->display_info();
        cout << "\n"
             << endl;
    }
    bool tc01_pass = (people.size() == 4);
    check(tc01_pass, "Test Case 01");

    //-----------------------------------------------------Test Case 02-----------------------------------------------------
    Patient patient2("Flu", "2023-10-05", "General Ward A", "Vaqas ", "1998-01-01", 502, "555-0000", 2, 100.0, "Doe");
    treatmeant t1("Consultation", 1000.0, "Dr. Deepak");
    patient1.add_treatment(t1);

    Bill b1 = patient1.generate_bill();
    Bill b2 = patient2.generate_bill();

    Bill combined = b1 + b2;

    cout << "\n-----------------------------------------------------Test Case 02-----------------------------------------------------\n"
         << endl;
    cout << "Bill 1 Total: " << b1.total() << endl;
    cout << "Bill 2 Total: " << b2.total() << endl;
    cout << "Combined Bill Output:\n"
         << combined << endl;

    bool tc02_pass = (b1.total() > 0 && b2.total() > 0 && combined.total() == (b1.total() + b2.total()));
    check(tc02_pass, "Test Case 02");
    //-----------------------------------------------------Test Case 03-----------------------------------------------------

    Ward w1("Ward A", 20);
    for (int i = 0; i < 5; i++)
    {
        Patient p;
        p.Id = 1000 + i;
        w1.add_patient(p);
    }

    ICU_ward w2;
    w2.set_name("ICU");
    w2.set_capacity(8);
    for (int i = 0; i < 7; i++)
    {
        Patient p;
        p.Id = 2000 + i;
        p.diagnosis = "critical";
        w2.add_patient(p);
    }

    cout << "\n-----------------------------------------------------Test Case 03-----------------------------------------------------" << endl;
    cout
        << w1.name << " Occupancy: " << (static_cast<double>(w1.patients.size()) / w1.capacity) * 100 << "%" << endl;
    cout << w2.name << " Occupancy: " << (static_cast<double>(w2.patients.size()) / w2.capacity) * 100 << "%" << endl;

    double w1_occ = (static_cast<double>(w1.patients.size()) / w1.capacity) * 100;
    double w2_occ = (static_cast<double>(w2.patients.size()) / w2.capacity) * 100;

    bool tc03_pass = (w1_occ == 25.0 && w2_occ == 87.5);
    check(tc03_pass, "Test Case 03");
    // -----------------------------------------------------Test Case 04-----------------------------------------------------

    Patient critical_p;
    critical_p.name = "Ali Khan";
    critical_p.Id = 601;
    critical_p.diagnosis = "critical";

    Patient routine_p;
    routine_p.name = "Sara Baig";
    routine_p.Id = 602;
    routine_p.diagnosis = "Sprained ankle";

    ICU_ward icu;
    icu.set_name("ICU");
    icu.set_capacity(10);

    Ward gw("General", 30);

    cout << "\n-----------------------------------------------------Test Case 04-----------------------------------------------------" << endl;

    icu.add_patient(critical_p);
    bool icu_accepts_critical = (icu.patients.size() == 1);

    icu.add_patient(routine_p);
    bool icu_rejects_routine = (icu.patients.size() == 1); // size should still be 1

    gw.add_patient(routine_p);
    bool gw_accepts_routine = (gw.patients.size() == 1);

    check(icu_accepts_critical && icu_rejects_routine && gw_accepts_routine, "Test Case 04 Admission Rule Enforcement");

    //-----------------------------------------------------Test Case 05-----------------------------------------------------
    cout << "\n-----------------------------------------------------Test Case 05-----------------------------------------------------" << endl;

    appointment_book book;

    appointment app1(patient1, &gp1, "2026-04-10", "10:00");
    bool first_ok = book.add_appointment(app1);

    appointment app2(patient2, &gp1, "2026-04-10", "10:00");
    bool second_result = book.add_appointment(app2);

    appointment app3(patient2, &gp1, "2026-04-10", "11:00");
    bool third_ok = book.add_appointment(app3);

    bool tc05_pass = (first_ok == true) && (second_result == false) && (third_ok == true);

    check(tc05_pass, "Test Case 05");

    //-----------------------------------------------------Test Case 06-----------------------------------------------------
    Patient original("Pneumonia", "2023-10-01", "General", "Hamid Raza", "1985-05-20", 701, "555-7777", 0, 0, "Raza");
    treatmeant t3("Blood test", 500, "Dr. Alvi");
    original.add_treatment(t3);

    Patient copy_patient = original;

    treatmeant t2("MRI", 8000, "Dr. Khan");
    copy_patient.add_treatment(t2);

    bool original_unchanged = (original.treatments.size() == 1);
    bool copy_updated = (copy_patient.treatments.size() == 2);

    cout << "\n-----------------------------------------------------Test Case 06-----------------------------------------------------" << endl;
    cout << "Original Treatment Count: " << original.treatments.size() << endl;
    cout << "Copy Treatment Count: " << copy_patient.treatments.size() << endl;

    check(original_unchanged && copy_updated, "Test Case 06");

    //-----------------------------------------------------Test Case 07-----------------------------------------------------

    cout << "\n-----------------------------------------------------Test Case 07-----------------------------------------------------" << endl;
    Hospital h;
    Patient p_move("Cardiac arrest", "2026-04-10", "ICU", "Hamid Raza", "1985-05-20", 801, "555-7777", 0, 0, "Raza");
    p_move.add_treatment(treatmeant("Oxygen", 200, "Nurse samiya"));

    h.admit(p_move);

    h.discharge(801);

    bool no_longer_live = (h.isAdmitted(801) == false);
    bool now_archived = (h.isArchived(801) == true);
    bool data_preserved = (h.archive.back().treatments.size() == 1);
    check(no_longer_live && now_archived && data_preserved, "Test Case 07");

    //-----------------------------------------------------Test Case 08-----------------------------------------------------

    Hospital hosp;
    Patient p_moved("critical", "date", "ICU", "MoveTest", "DOB", 801, "ph", 0, 0, "Test");
    hosp.admit(p_moved);
    hosp.discharge(801);
    check(hosp.live_records.empty() && !hosp.archive.empty(), "Test Case 08");

    hosp.admit(patient1);
    hosp.admit(patient2);
    auto critQuery = hosp.filterPatients([](const Patient &p)
                                         { return p.diagnosis == "Pneumonia" && p.ward == "General Ward A"; });
    hosp.sortPatients([](const Patient &a, const Patient &b)
                      { return a.sur_name < b.sur_name; });

    check(hosp.live_records.empty() && !hosp.archive.empty(), "Test Case 08 | Move Records");

    check(!critQuery.empty(), "Test Case 08 | Lambda Filtering");

    //-----------------------------------------------------Test Case 09-----------------------------------------------------

    general_practitioner gp_test("Dr. GP", "DOB", 201, "ph", 80000, "Gen", 1500.0);
    Surgeon sur_test("Dr. Surgeon", "DOB", 202, "ph", 150000, "Surg", 5000.0, "Heart");
    Nurse nur_test("Nurse samiya", "DOB", 203, "ph", 50000, "Ward", 500.0, "ICU");

    vector<Employee *> staff_list = {&gp_test, &sur_test, &nur_test};

    cout << "\n-----------------------------------------------------Test Case 09-----------------------------------------------------" << endl;

    bool rates_differ = true;
    double last_rate = -1.0;

    for (auto *s : staff_list)
    {
        double current_rate = s->get_fee();
        ;
        cout << s->name << ": PKR " << current_rate << endl;

        if (current_rate == last_rate)
            rates_differ = false;
        last_rate = current_rate;
    }
    check(rates_differ && staff_list.size() == 3, "Test Case 09 | Staff Billing Rate Polymorphism");

    //-----------------------------------------------------est Case 10-----------------------------------------------------
    cout << "\n-----------------------------------------------------Test Case 10-----------------------------------------------------" << endl;
    Hospital revenueHosp;

    Patient rp1("D1", "date", "Ward A", "P1", "DOB", 1001, "ph", 0, 0, "S1");
    Patient rp2("D2", "date", "Ward A", "P2", "DOB", 1002, "ph", 0, 0, "S2");
    Patient rp3("D3", "date", "Ward A", "P3", "DOB", 1003, "ph", 0, 0, "S3");

    rp1.add_treatment(treatmeant("T1", 9500, "Staff"));
    rp2.add_treatment(treatmeant("T2", 14500, "Staff"));
    rp3.add_treatment(treatmeant("T3", 7500, "Staff"));

    revenueHosp.admit(rp1);
    revenueHosp.admit(rp2);
    revenueHosp.admit(rp3);

    revenueHosp.discharge(1001);
    revenueHosp.discharge(1002);
    revenueHosp.discharge(1003);

    double revenue = revenueHosp.wardRevenue("Ward A");
    cout << "Calculated Revenue for Ward A: PKR " << revenue << endl;
    check(abs(revenue - 33000.0) < 0.001, "Test Case 10 | Revenue Accumulation");

    cout << "\n\nAll test cases test\n";
    check(tc01_pass, "Test Case 01");
    check(tc02_pass, "Test Case 02");
    check(tc03_pass, "Test Case 03");
    check(icu_accepts_critical && icu_rejects_routine && gw_accepts_routine, "Test Cas8e 04");
    check(tc05_pass, "Test Case 05");
    check(original_unchanged && copy_updated, "Test Case 06");
    check(no_longer_live && now_archived && data_preserved, "Test Case 07");
    check(!critQuery.empty(), "Test Case 08");
    check(rates_differ && staff_list.size() == 3, "Test Case 09");
    check(abs(revenue - 33000.0) < 0.001, "Test Case 10");

    return 0;
}
