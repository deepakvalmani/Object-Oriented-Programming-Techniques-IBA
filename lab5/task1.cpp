#include <iostream>

using namespace std;

class IntNum
{
private:
    int n;

public:
    IntNum()
    {
        n = 4;
    }

    IntNum &operator--()
    {
        this->n *= 4;
        return *this;
    }

    IntNum operator--(int)
    {
        this->n /= 4;
        return *this;
    }

    void Display()
    {
        cout << "Number is: " << n << endl;
    }
};

int main()
{
    IntNum IntNumber1;
    IntNumber1.Display();

    --IntNumber1;
    IntNumber1.Display();

    IntNumber1--;
    IntNumber1.Display();
    return 0;
}
