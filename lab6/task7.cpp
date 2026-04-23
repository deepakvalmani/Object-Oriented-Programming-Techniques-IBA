#include <iostream>
using namespace std;

class Vehicle
{
protected:
    string registrationNo;
    string brand;
    double dailyRate;

public:
    Vehicle(string registrationNo, string brand, double dailyRate)
    {
        this->registrationNo = registrationNo;
        this->brand = brand;
        this->dailyRate = dailyRate;
    }

    virtual void displayVehicle()
    {
        cout << "Registration No: " << registrationNo << endl;
        cout << "Brand: " << brand << endl;
        cout << "Daily Rate: " << dailyRate << endl;
    }

    virtual double calculateRentalCost(int days)
    {
        return dailyRate * days;
    }
};

class Car : public Vehicle
{
private:
    int numDoors;

public:
    Car(string registrationNo, string brand, double dailyRate, int numDoors)
        : Vehicle(registrationNo, brand, dailyRate)
    {
        this->numDoors = numDoors;
    }

    void displayVehicle() override
    {
        Vehicle::displayVehicle();
        cout << "Number of Doors: " << numDoors << endl;
    }
};

class ElectricCar : public Car
{
private:
    double batteryCapacity; // in kWh

public:
    ElectricCar(string registrationNo, string brand, double dailyRate,
                int numDoors, double batteryCapacity)
        : Car(registrationNo, brand, dailyRate, numDoors)
    {
        this->batteryCapacity = batteryCapacity;
    }

    void displayVehicle() override
    {
        Car::displayVehicle();
        cout << "Battery Capacity: " << batteryCapacity << " kWh" << endl;
    }

    double calculateRentalCost(int days) override
    {
        double total = dailyRate * days;
        return total * 0.85; // 15% green discount
    }
};

class Truck : private Vehicle
{
private:
    double payloadCapacity; // in tonnes

public:
    Truck(string registrationNo, string brand, double dailyRate, double payloadCapacity)
        : Vehicle(registrationNo, brand, dailyRate)
    {
        this->payloadCapacity = payloadCapacity;
    }

    void displayTruck()
    {
        Vehicle::displayVehicle();
        cout << "Payload Capacity: " << payloadCapacity << " tonnes" << endl;
    }

    /*
    Even though registrationNo is protected in Vehicle,
    because Truck inherits Vehicle privately, all public
    and protected members of Vehicle become private inside Truck.
    Therefore, they cannot be accessed from main().
    They are still accessible inside Truck’s member functions.
    */
};

int main()
{
    Car c("ABC123", "Toyota", 5000, 4);
    ElectricCar e("EV456", "Tesla", 8000, 4, 75);
    Truck t("TR789", "Volvo", 10000, 10);

    cout << "Car" << endl;
    c.displayVehicle();

    cout << "\nElectric Car" << endl;
    e.displayVehicle();
    cout << "7-Day Rental Cost (after 15% discount): "
         << e.calculateRentalCost(7) << endl;

    cout << "\nTruck" << endl;
    t.displayTruck();

    return 0;
}