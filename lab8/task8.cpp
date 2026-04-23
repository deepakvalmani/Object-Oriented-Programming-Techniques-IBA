#include <iostream>
using namespace std;

class PoweredSystem
{

public:
    PoweredSystem()
    {
        cout << "PoweredSystem called\n";
    }
};

class Vehicle : virtual public PoweredSystem
{
public:
    Vehicle()
    {
        cout << "Vehicle called\n";
    }
};

class Engine : virtual public PoweredSystem
{
public:
    Engine()
    {
        cout << "Engine called\n";
    }
};

class Car : public Engine, public Vehicle
{

public:
    Car()
    {
        cout << "Car called\n";
    }
};

int main()
{

    Car c;

    return 0;
}