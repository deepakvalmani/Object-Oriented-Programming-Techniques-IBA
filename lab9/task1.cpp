#include <iostream>

using namespace std;

double add(double a, double b) { return a + b; };
double subtract(double a, double b) { return a - b; };
double multiply(double a, double b) { return a * b; };
double devision(double a, double b)
{
    if (b != 0)
        return a / b;
    else
    {
        throw("devision by zero error!");
    }
};

typedef double (*BinaryOp)(double, double);

double applyOp(double x, double y, BinaryOp op) { return op(x, y); }

int main()
{

    BinaryOp ops[] = {add, subtract, multiply, devision};
    const char *names[] = {"add", "subtracct", "multiply", "devision"};

    double a = 15.0, b = 4.0;
    for (int i = 0; i < 4; i++)
        cout
            << names[i] << "(15.0, 4.0) = " << applyOp(a, b, ops[i]) << "\n";

    return 0;
}