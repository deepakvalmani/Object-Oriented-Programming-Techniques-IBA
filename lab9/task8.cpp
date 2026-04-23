#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <numeric>

using namespace std;

struct Order
{
    int id;
    string customer;
    double amount;
    bool isPaid;
};

int main()
{
    vector<Order> orders = {
        {1, "Ali", 120.0, true},
        {2, "Sara", 80.0, true},
        {3, "John", 200.0, false},
        {4, "Ayesha", 150.0, true},
        {5, "David", 95.0, true},
        {6, "Zain", 300.0, true},
        {7, "Emma", 50.0, false},
        {8, "Noah", 180.0, true}};

    vector<Order> filtered;

    copy_if(orders.begin(), orders.end(), back_inserter(filtered),
            [](const Order &o)
            { return o.isPaid && o.amount > 100; });


    vector<double> discounted;

   transform(filtered.begin(), filtered.end(), back_inserter(discounted),
            [](const Order &o)
            { return o.amount * 0.9; });

    auto total = std::reduce(discounted.begin(), discounted.end(), 0.0);
    int count = discounted.size();

    cout << fixed << setprecision(2);
    cout << "Qualifying Orders: " << count << endl;
    cout << "Total Discounted Revenue: " << total << endl;

    return 0;
}