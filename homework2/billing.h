#ifndef BILLING_H
#define BILLING_H

#include <iostream>
using namespace std;

class Bill
{
public:
    double treatment_cost;
    double ward_fee;
    double admin_fee;

    Bill()
    {
        treatment_cost = 0;
        ward_fee = 0;
        admin_fee = 500;
    }

    double total() const
    {
        return treatment_cost + ward_fee + admin_fee;
    }

    // compare bills
    bool operator==(const Bill &other) const
    {
        return total() == other.total();
    }

    // add bills
    Bill operator+(const Bill &other) const
    {
        Bill result;
        result.treatment_cost = this->treatment_cost + other.treatment_cost;
        result.ward_fee = this->ward_fee + other.ward_fee;
        result.admin_fee = this->admin_fee + other.admin_fee;
        return result;
    }

    // print bill
    friend ostream &operator<<(ostream &out, const Bill &b)
    {
        out << "Treatment Cost: " << b.treatment_cost << endl;
        out << "Ward Fee: " << b.ward_fee << endl;
        out << "Admin Fee: " << b.admin_fee << endl;
        out << "Total: " << b.total() << endl;
        return out;
    }

};

#endif
