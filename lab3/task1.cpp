#include <iostream>
using namespace std;

class CrystalPair
{
private:
    int *power;
    string name;
    string mode;
    bool ownsMemory;

public:
    CrystalPair(string name = "bob", int power1 = 0, int power2 = 0, string mode = "practice")
    {
        this->name = name;
        this->mode = mode;
        power = new int[2];
        power[0] = power1;
        power[1] = power2;

        ownsMemory = true;
    }

    CrystalPair(const CrystalPair &s)
    {
        name = s.name;
        mode = s.mode;

        if (s.mode == "battle")
        {
            power = new int[2];
            power[0] = s.power[0];
            power[1] = s.power[1];
            ownsMemory = true;
        }
        else
        {
            power = s.power;
            ownsMemory = false;
        }
    }

    int sum()
    {
        return (power[0] + power[1]);
    }

    void set_name(string name)
    {
        this->name = name;
    }

    void set_power(int p1, int p2)
    {
        power[0] = p1;
        power[1] = p2;
    }

    void show()
    {
        cout << "Name: " << name << endl;
        cout << "Mode: " << mode << endl;
        cout << "\tPower 1: " << power[0] << endl;
        cout << "\tPower 2: " << power[1] << endl;
        cout << "\tTotal Power: " << sum() << endl;
    }

    ~CrystalPair()
    {
        if (ownsMemory)
            delete[] power;
    }
};

int main()
{
    CrystalPair p1("Deepak", 2, 3, "battle");
    cout << "Original Player (Battle Mode):" << endl;
    p1.show();
    cout << endl;

    CrystalPair p2(p1);
    cout << "Copied Player (Battle Mode Copy):" << endl;
    p2.show();
    cout << endl;

    cout << "Modifying Copied Player.........." << endl;
    p2.set_name("Bob");
    p2.set_power(10, 15);
    cout << endl;

    cout << "After Modification (Battle Mode):" << endl;
    p2.show();
    cout << endl;
    p1.show();
    cout << endl;

    CrystalPair p3("Alice", 5, 7, "practice");
    cout << "Original Player (Practice Mode):" << endl;
    p3.show();
    cout << endl;

    CrystalPair p4(p3);
    cout << "Copied Player (Practice Mode Copy):" << endl;
    p4.show();
    cout << endl;

    cout << "Modifying Copied Player.........." << endl;
    p4.set_name("Charlie");
    p4.set_power(100, 200);
    cout << endl;

    cout << "After Modification (Practice Mode):" << endl;
    p4.show();
    cout << endl;
    p3.show();

    return 0;
}
