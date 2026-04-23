#include <iostream>
#include <vector>
#include <functional>

using namespace std;

// Functor class
class Multiplier
{
    int callCount = 0;
    double factor;

public:
    Multiplier(double factor)
    {
        this->factor = factor;
    }

    double operator()(double x)
    {
        callCount++;
        return x * factor;
    }

    int getCount() const
    {
        return callCount;
    }
};

// Standalone dispatch function
void dispatch(double val, vector<function<double(double)>> &handlers)
{
    for (auto &h : handlers)
    {
        cout << h(val) << " ";
    }
    cout << endl;
}

int main()
{
    Multiplier m2(2);
    Multiplier m3(3);
    Multiplier m5(5);

    vector<function<double(double)>> handlers;

    // register (IMPORTANT: use ref)
    handlers.push_back(ref(m2));
    handlers.push_back(ref(m3));
    handlers.push_back(ref(m5));

    // dispatch value
    dispatch(6.0, handlers);

    // print call counts
    cout << "Call Counts:\n";
    cout << "m2: " << m2.getCount() << endl;
    cout << "m3: " << m3.getCount() << endl;
    cout << "m5: " << m5.getCount() << endl;

    return 0;
}