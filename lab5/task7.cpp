#include <iostream>
using namespace std;

class Multiplication
{
public:
    int multiply(int a, int b)
    {
        return a * b;
    }
    int multiply(int a, int b, int c)
    {
        return a * b * c;
    }
    double multiply(double a, double b)
    {
        return a * b;
    }
    double multiply(double a, double b, double c)
    {
        return a * b * c;
    }
};
int main()
{
    Multiplication m;
    cout << "Multiplication of 2 integers  " << m.multiply(2, 3) << endl;
    cout << "Multiplication of 3 integers  " << m.multiply(2, 3, 4) << endl;
    cout << "Multiplication of 2 double   " << m.multiply(2.1, 3.1) << endl;
    cout << "Multiplication of 3 double   " << m.multiply(2.1, 3.1, 4.1) << endl;

    return 0;
}