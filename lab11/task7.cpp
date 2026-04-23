#include <iostream>
#include <vector>
using namespace std;

/*

int factorial(int n) {
    return n * factorial(n - 1);
}

Missing base case
Function never stops

Add stopping condition when n == 0
*/

int factorial(int n)
{
    // base case added
    if (n == 0)
        return 1;

    return n * factorial(n - 1);
}

/*

return s[0] + reverse(s.substr(1));

Wrong order of concatenation
This produces same string instead of reverse

Reverse rest first then add current character

*/

string reverseStr(const string &s)
{
    if (s.size() == 0)
        return "";

    // FIXED ORDER
    return reverseStr(s.substr(1)) + s[0];
}

/*

return sum(arr, i + 1);
did not  include arr[i]
So all values were skipped so result always 0

Add current element before recursion
*/

int sum(const vector<int> &arr, int i = 0)
{
    if (i == (int)arr.size())
        return 0;

    // include arr[i]
    return arr[i] + sum(arr, i + 1);
}

int main()
{
    vector<int> arr = {1, 2, 3};

    cout << "Factorial(3): " << factorial(3) << endl;
    cout << "Reverse(abc): " << reverseStr("abc") << endl;
    cout << "Sum: " << sum(arr) << endl;

    return 0;
}