#include <iostream>
using namespace std;

template <typename A>

void swap_values(A &a1, A &a2)
{
    A temp = a1;
    a1 = a2;
    a2 = temp;
}

int main()
{
    int x = 3;
    int y = 5;

    swap_values(x, y);
    cout << "X = " << x << endl;
    cout << "Y = " << y << endl;

    int a = 'A';
    int b = 'B';

    swap_values(a, b);
    cout << "A = " << char(a) << endl;
    cout << "B = " << char(b) << endl;

    return 0;
}