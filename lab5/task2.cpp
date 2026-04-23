#include <iostream>
using namespace std;
class Shape
{
    int side_len;

public:
    Shape(double s)
    {
        side_len = s;
    }
    double Area()
    {
        return side_len * side_len;
    }
    double operator+(Shape s)
    {
        return this->Area() + s.Area();
    }
};
int main()
{
    Shape shape1(3);
    Shape shape2(9);
    double total_area = shape1 + shape2;

    cout << "Area of shape1 = " << shape1.Area() << endl;
    cout << "Area of shape2 = " << shape2.Area() << endl;
    cout << "Total Area = " << total_area << endl;

    return 0;
}