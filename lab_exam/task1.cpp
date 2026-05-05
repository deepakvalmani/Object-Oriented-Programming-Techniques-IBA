#include <iostream>
using namespace std;

class Vehicle
{
protected:
    string brand;

public:
    Vehicle(string b) { brand = b; };
    virtual double top_speed() const = 0;
    virtual void display() const = 0;

    virtual ~Vehicle() {}
};

class MotorVehicle : public Vehicle
{

protected:
    bool electric;

public:
    MotorVehicle(string b, bool e) : Vehicle(b) { electric = e; };
    virtual bool is_electric() const = 0;
};

class Car : public MotorVehicle
{

private:
    double engine_power;

public:
    Car(string b, bool e, double ep) : MotorVehicle(b, e) { engine_power = ep; };

    double top_speed() const override
    {
        return engine_power * 2.5;
    };
    bool is_electric() const override
    {
        return electric;
    };

    void display() const override
    {
        cout << "Brand: "
             << brand
             << "\nPower: "
             << engine_power
             << "\nElectric status: "
             << electric
             << endl;
    }

    double operator+(const Car &other) const
    {
        return this->top_speed() + other.top_speed();
    };

    friend ostream &operator<<(ostream &os,const Car &c)
    {
        c.display();
        return os;
    }
};
int main()
{
    Vehicle *c1 = new Car("Honda civic", true, 300);
    Vehicle *c2 = new Car("Toyota", false, 500);

    cout << *(dynamic_cast<Car *>(c1)) << endl;
    cout << *(dynamic_cast<Car *>(c2)) << endl;

    MotorVehicle *m1 = dynamic_cast<MotorVehicle *>(c1);
    MotorVehicle *m2 = dynamic_cast<MotorVehicle *>(c2);

    if (m1)
    {
        cout << "Car 1 is ";
        (m1->is_electric() ? cout << "is electric\n" : cout << "is not electric\n");
    }

    if (m2)
    {
        cout << "Car 2 is ";
        (m2->is_electric() ? cout << "is electric\n" : cout << "is not electric\n");
    }

    Car *cr1 = (dynamic_cast<Car *>(c1));
    Car *cr2 = (dynamic_cast<Car *>(c2));
    double topspeed = *cr1 + *cr2;

    cout << "Sum is " << topspeed<< endl;

    delete c1;
    delete c2;

    return 0;
}