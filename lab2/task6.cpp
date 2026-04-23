#include <iostream>
using namespace std;

class OxygenTank
{
public:
    int oxygenLevel;
    OxygenTank()
    {
        oxygenLevel = 200;
    }

    void Consume(int units)
    {
        if (oxygenLevel < 100)
            refill();
        oxygenLevel -= units;
    }

    void refill()
    {
        oxygenLevel = 200;
    }
};

int main()
{
    int units = 1;
    OxygenTank t;
    while (units)
    {
        cout << "enter no of units you want to consume: " << endl;
        cin >> units;
        t.Consume(units);
        cout << t.oxygenLevel << " is your current oxygen level" << endl;
    }

    return 0;
}