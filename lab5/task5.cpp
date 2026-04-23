#include <iostream>
#include <cmath>
using namespace std;

class Shape
{
public:
    virtual void calculateArea()
    {
        cout << "Calculating area of a shape." << endl;
    }

    virtual ~Shape() {}
};

class Rectangle : public Shape
{
    double length, width;

public:
    Rectangle(double l, double w)
    {
        length = l;
        width = w;
    }

    void calculateArea() override
    {
        double area = length * width;
        cout << "Area of Rectangle: " << area << endl;
    }
};

class Circle : public Shape
{
    double radius;

public:
    Circle(double r)
    {
        radius = r;
    }

    void calculateArea() override
    {
        double area = 3.142 * radius * radius;
        cout << "Area of Circle: " << area << endl;
    }
};

class Triangle : public Shape
{
    double a, b, c;

public:
    Triangle(double x, double y, double z)
    {
        a = x;
        b = y;
        c = z;
    }

    void calculateArea() override
    {
        double s = (a + b + c) / 2;
        double area = sqrt(s * (s - a) * (s - b) * (s - c));
        cout << "Area of Triangle: "
             << area << endl;
    }
};

int main()
{
    Shape* shape = nullptr;

    int sides;
    cout << "Enter number of sides (1 for Circle, 2 for Rectangle, 3 for Triangle): ";
    cin >> sides;

    if (sides == 1)
    {
        double r;
        cout << "Enter radius: ";
        cin >> r;
        shape = new Circle(r);
    }
    else if (sides == 2)
    {
        double l, w;
        cout << "Enter length and width: ";
        cin >> l >> w;
        shape = new Rectangle(l, w);
    }
    else if (sides == 3)
    {
        double a, b, c;
        cout << "Enter sides a, b, c: ";
        cin >> a >> b >> c;
        shape = new Triangle(a, b, c);
    }
    else
    {
        cout << "Invalid input!" << endl;
        return 0;
    }

    shape->calculateArea();

    delete shape;

    return 0;
}