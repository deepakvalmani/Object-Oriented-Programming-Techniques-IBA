#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Rational
{
private:
    int num, den;

    int gcd(int a, int b)
    {
        return (b == 0) ? a : gcd(b, a % b);
    }

public:
    Rational(int n = 0, int d = 1) : num(n), den(d) {}

    // Constructor using string
    Rational(string s)
    {
        int pos = s.find('/');
        num = stoi(s.substr(0, pos));
        den = stoi(s.substr(pos + 1));
        
    }

    // Constructor using double
    Rational(double value)
    {
        const int precision = 1000;
        num = round(value * precision);
        den = precision;
        reduce();
    }

    void reduce()
    {
        int g = gcd(abs(num), abs(den));
        num /= g;
        den /= g;
    }

    int Get_num() { return num; }
    int Get_den() { return den; }

    void Set_num(int n) { num = n; }
    void Set_den(int d) { den = d; }

    string to_string()
    {
        return std::to_string(num) + "/" + std::to_string(den);
    }

    void show()
    {
        cout << "Number: " << num << "/" << den << endl;
    }

    // Operator Overloading
    Rational operator+(const Rational &r)
    {
        return Rational(num * r.den + r.num * den, den * r.den);
    }

    Rational operator-(const Rational &r)
    {
        return Rational(num * r.den - r.num * den, den * r.den);
    }

    Rational operator*(const Rational &r)
    {
        return Rational(num * r.num, den * r.den);
    }

    Rational operator/(const Rational &r)
    {
        return Rational(num * r.den, den * r.num);
    }

    bool operator==(const Rational &r)
    {
        return (num == r.num && den == r.den);
    }

    bool operator!=(const Rational &r)
    {
        return (num != r.num || den != r.den);
    }
};

int main()
{
    Rational r("6/4");
    r.show();
    

    Rational d(0.75);
    d.show();

    return 0;
}
