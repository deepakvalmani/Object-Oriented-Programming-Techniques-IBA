#include <iostream>
using namespace std;

template <typename A>

A max_value(A a1, A a2, A a3)
{
    A max;
    if (a1 > a2)
        max = a1;
    else
        max = a2;
    if (a3 > max)
        max = a3;

    return max;
}

int main()
{
    cout << max_value(1, 2, 3)<<endl;
    cout << max_value(2.5, 7.1, 3.3) << endl; // works with doubles

    return 0;
}