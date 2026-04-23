#include <iostream>
using namespace std;

class Glass
{
private:
    int liquidLevel;

public:
    Glass()
    {
        liquidLevel = 200;
    }

    void drink(int quantity)
    {
        if (quantity > liquidLevel)
        {
            cout << "Not enough liquid in the glass!" << endl;
        }
        else
        {
            liquidLevel -= quantity;
        }
    }

    void refill()
    {
        liquidLevel = 200;
        cout << "Glass refilled." << endl;
    }

    int getLevel() const
    {
        return liquidLevel;
    }
};

int main()
{
    Glass g1;
    int val = -1;

    while (val != 0)
    {
        cout << "Current liquid level: " << g1.getLevel() << endl;
        cout << "Enter amount to drink (0 to exit): ";
        cin >> val;

        if (val == 0)
            break;

        g1.drink(val);

        if (g1.getLevel() == 0)
        {
            g1.refill();
        }
    }

    return 0;
}
