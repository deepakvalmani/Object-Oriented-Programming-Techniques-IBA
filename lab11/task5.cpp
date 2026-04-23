#include <iostream>
#include <vector>

using namespace std;

int sumDigits(int n)
{
    if (n < 10)
    {
        return n;
    }
    int num = n % 10;
    return num + sumDigits(n / 10);
}

int main()
{
    cout << "Sum of digits of 0: " << sumDigits(0) << endl;
    cout << "Sum of digits of 9: " << sumDigits(9) << endl;
    cout << "Sum of digits of 123: " << sumDigits(123) << endl;
    cout << "Sum of digits of 9999: " << sumDigits(9999) << endl;

    return 0;
}