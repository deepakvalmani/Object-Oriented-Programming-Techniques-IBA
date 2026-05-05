#include <iostream>
#include <vector>
using namespace std;

template <typename F>

void apply_to_all(vector<int> &v, F func)
{
    for (int val : v)
    {
        func(val);
    }
}

void print_double(int x)
{
    cout << x * 2 << " ";
}

int main()
{

    vector<int> nums = {1, 2, 3, 4, 5};
    apply_to_all(nums, print_double);
    cout << endl;
    return 0;
}