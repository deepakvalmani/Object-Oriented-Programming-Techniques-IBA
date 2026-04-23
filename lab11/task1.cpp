#include <iostream>
using namespace std;

int factorial(int n)
{
    cout << "Entering factorial(" << n << ")" << endl;

    if (n == 0 || n == 1)
    {
        return 1;
    }

    int result = n * factorial(n - 1);

    cout << "Returning factorial(" << n << ") = " << result << endl;

    return result;
}

int main()
{
    int result = factorial(5);
    cout << "Final result: " << result << endl;
    return 0;
}