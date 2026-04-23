#include <iostream>
#include <functional>

using namespace std;

function<int()> makeCounter(int start, int step)
{
    return [start, step]() mutable
    {
        start += step;
        return start;
    };
}

int main()
{
    
    auto byOne = makeCounter(0, 1);
    auto byFive = makeCounter(0, 5);
    auto countdown = makeCounter(20, -3);
    cout << "byOne = ";
    for (int i = 0; i < 5; i++)
    {
        cout << byOne()<<" ";
    }
    cout << endl;

    cout << "byFive = ";
    for (int i = 0; i < 5; i++)
    {
        cout << byFive()<<" ";
    }
    cout << endl;
    cout << "countdown = ";
    for (int i = 0; i < 5; i++)
    {
        cout << countdown()<<" ";
    }
    cout << endl;

    return 0;
}