#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool is_Even(int x) { return x % 2 == 0; };
bool is_Odd(int x) { return x % 2 != 0; };
int Count_if(vector<int> &v, bool (*predicate)(int))
{
    int count = 0;
    for (int val : v)
    {
        if (predicate(val))
            ++count;
    }
    return count;
}

int main()
{
    vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    cout << "Even count: " << Count_if(numbers, is_Even);
    cout << "\nOdd count: " << Count_if(numbers, is_Odd);

    return 0;
}