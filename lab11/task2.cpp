#include <iostream>
using namespace std;

int count_a = 0;
int fib(int n)
{
    count_a++;
    if (n == 0 || n == 1)
    {
        return n;
    }
    return fib(n - 1) + fib(n - 2);
}


int main()
{
    int arr[] = {1, 5, 10, 15, 20};
    for (int i = 0; i < 5; i++)
    {count_a = 0;
        fib(arr[i]);
        cout << "fib("
             << arr[i]
             << ")\t"
             << "count: "
             << count_a
             << "\n";
    }

    cout << "count: " << count_a;

    return 0;
}

// as n increases the number of calls increases becasue the code is not efficient so it calls 
//every number again and again if we implement an efficient algorithm we can skip the unnesessary calls