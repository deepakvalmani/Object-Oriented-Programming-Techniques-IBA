#include <iostream>
using namespace std;

class Base
{
public:
    Base()
    {
    }

    virtual double area() = 0;


    virtual ~Base(){

    }
};

class Circle : public Base
{

private:
    double radius;

public:
    Circle(double r)
    {
        radius = r;
    }

    double area() override
    {
        return (3.1475 * radius * radius);
    }
};

class Rectangle : public Base
{

private:
    double length, width;

public:
    Rectangle(double l, double w)
    {
        length = l;
        width = w;
    }

    double area() override
    {
        return (length * width);
    }
};

class Triangle : public Base
{

private:
    double height, base;

public:
    Triangle(double b, double h)
    {
        height = h;
        base = b;
    }

    double area() override
    {
        return (0.5 * height * base);
    }
};

int main()
{

    Base *circle = new Circle(5.5);
    Base *rectangle = new Rectangle(8, 4.2);
    Base *triangle = new Triangle(6, 3.5);

    cout<<"\nCircle Area: "<<circle->area();
    cout<<"\nRectangle Area: "<<rectangle->area();
    cout<<"\nTriangle Area: "<<triangle->area();

    delete circle;
    delete rectangle;
    delete triangle;

    return 0;
}