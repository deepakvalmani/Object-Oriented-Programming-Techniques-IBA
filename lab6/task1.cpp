#include <iostream>
using namespace std;

class Shape
{
protected:
    string color;

public:
    void displayColor()
    {
        cout << "Color is: " << color << endl;
    }
};

class Circle : public Shape
{
private:
    double radius;

public:
    void Area()
    {
        double area = 4 * radius * 3.14159;
        cout << "Area = " << area << endl;
    }

    void SetColor(string cl)
    {
        color = cl;
    }

    void SetRadius(double r)
    {
        radius = r;
    }

    // here the color variable is accessible because it is protected in shape class
    // Class circle has inherited the shape class in public mode
};
int main()
{

    Circle c;
    c.SetColor("blue");
    c.SetRadius(12);
    c.displayColor();
    c.Area();

    return 0;
}