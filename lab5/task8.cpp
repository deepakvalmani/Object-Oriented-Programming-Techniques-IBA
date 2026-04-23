#include <iostream>
using namespace std;

class Vehicle
{
protected:
    double rentalPricePerDay;
    string vehicleType;

public:
    Vehicle(double price, string type)
    {
        rentalPricePerDay = price;
        vehicleType = type;
    }

    virtual double rent(int days) = 0; // Pure virtual

    virtual void displayInfo()
    {
        cout << "Vehicle Type: " << vehicleType << endl;
        cout << "Rental Price Per Day: " << rentalPricePerDay << endl;
    }

    // Function Overloading for payment methods
    void rent(int days, string paymentMethod)
    {
        double cost = rent(days);
        cout << "Total Rental Cost: " << cost << endl;
        cout << "Payment Method: " << paymentMethod << endl;
    }

    void rent(int days, double paymentAmount)
    {
        double cost = rent(days);
        cout << "Total Rental Cost: " << cost << endl;
        cout << "Payment Amount Received: " << paymentAmount << endl;

        if (paymentAmount >= cost)
            cout << "Payment Successful. Change: " << paymentAmount - cost << endl;
        else
            cout << "Insufficient Payment!" << endl;
    }

    // Operator Overloading (+) to compare rental cost for 1 day
    bool operator+(Vehicle &other)
    {
        return this->rentalPricePerDay < other.rentalPricePerDay;
    }

    virtual ~Vehicle() {}
};

class Car : public Vehicle
{
    bool airConditioning;
    int seats;

public:
    Car(double price) : Vehicle(price, "Car")
    {
        airConditioning = true;
        seats = 5;
    }

    double rent(int days) override
    {
        double total = rentalPricePerDay * days;
        if (days > 7)
            total *= 0.90; // 10% discount
        return total;
    }

    void displayInfo() override
    {
        Vehicle::displayInfo();
        cout << "Air Conditioning: Yes" << endl;
        cout << "Seats: " << seats << endl;
    }
};

class Bike : public Vehicle
{
    bool helmetIncluded;
    string fuelType;

public:
    Bike(double price) : Vehicle(price, "Bike")
    {
        helmetIncluded = true;
        fuelType = "Petrol";
    }

    double rent(int days) override
    {
        double total = rentalPricePerDay * days;
        if (days > 3)
            total *= 0.95; // 5% discount
        return total;
    }

    void displayInfo() override
    {
        Vehicle::displayInfo();
        cout << "Helmet Included: Yes" << endl;
        cout << "Fuel Type: " << fuelType << endl;
    }
};

class Truck : public Vehicle
{
    double cargoCapacity;
    int wheels;

public:
    Truck(double price) : Vehicle(price, "Truck")
    {
        cargoCapacity = 10.0; // tons
        wheels = 6;
    }

    double rent(int days) override
    {
        double total = rentalPricePerDay * days;
        if (days > 5)
            total *= 1.20; // 20% surcharge
        return total;
    }

    void displayInfo() override
    {
        Vehicle::displayInfo();
        cout << "Cargo Capacity: " << cargoCapacity << " tons" << endl;
        cout << "Wheels: " << wheels << endl;
    }
};

int main()
{
    Vehicle *v1 = new Car(100);
    Vehicle *v2 = new Bike(50);

    cout << "Customer 1: Renting Car for 10 days (Credit Card)\n";
    v1->displayInfo();
    v1->rent(10, "Credit Card");

    cout << "\nCustomer 2: Renting Bike for 4 days (Cash)\n";
    v2->displayInfo();
    v2->rent(4, 250);

    cout << "\nComparing Vehicles (1 day cost):\n";
    if (*v1 + *v2)
        cout << "Bike is cheaper than Car.\n";
    else
        cout << "Car is cheaper than Bike.\n";

    delete v1;
    delete v2;

    return 0;
}