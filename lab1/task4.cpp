#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class Polynomial
{
private:
    int a, b, c;

public:
    // (a) Default constructor
    Polynomial()
    {
        a = 1;
        b = 1;
        c = 1;
    }

    // (b) Parameterized constructor
    Polynomial(int a, int b, int c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }

    // (c) format function
    string format() const
    {
        return to_string(a) + "x^2 + " +
               to_string(b) + "x + " +
               to_string(c);
    }

    // (d) eval function
    int eval(int x) const
    {
        return a * x * x + b * x + c;
    }

    // (e) Overload + operator
    Polynomial operator+(const Polynomial &other) const
    {
        return Polynomial(
            a + other.a,
            b + other.b,
            c + other.c);
    }

    // (f) Overload [] operator
    int &operator[](int index)
    {
        if (index == 0)
            return a;
        if (index == 1)
            return b;
        if (index == 2)
            return c;

        exit(1); // invalid index
    }

    // (g) Overload == operator
    bool operator==(const Polynomial &other) const
    {
        return (a == other.a &&
                b == other.b &&
                c == other.c);
    }
};

int main()
{
    Polynomial p;          // default constructor
    Polynomial q(2, 3, 4); // parameterized constructor

    cout << "p(x) = " << p.format() << endl;
    cout << "q(x) = " << q.format() << endl;

    cout << "p(2) = " << p.eval(2) << endl;
    cout << "q(2) = " << q.eval(2) << endl;

    Polynomial r = p + q;
    cout << "r(x) = p + q = " << r.format() << endl;

    // Using [] operator
    r[0] = 5;
    r[1] = 10;
    r[2] = 20;
    cout << "Modified r(x) = " << r.format() << endl;

    // Equality check
    Polynomial s(5, 10, 20);
    if (r == s)
        cout << "r and s are equal" << endl;
    else
        cout << "r and s are not equal" << endl;

    return 0;
}
