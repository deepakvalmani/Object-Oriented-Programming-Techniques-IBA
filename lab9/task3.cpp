#include <iostream >
using namespace std;
int main()
{
    int min = 10;
    int max = 50;
    int count = 0;

    // Capture by value (copy) - base inside lambda is independent
    auto inRange = [min, max](int x)
    {
        return (x >= min && x <= max);
    };

    auto CountInRange = [&count, inRange](int x)
    {
        if (inRange(x))
            count++;
        return count;
    };

    auto ScaleAndCheck = [inRange](auto x, auto factor)
    {
        auto scalled = factor * x;
        if (inRange(scalled))
        {
            return scalled;
        }
        return -1;
    };

    int arr[] = {7, 11, 35, 70, 40};

    for (int i = 0; i < 5; i++)
    {
        int val = arr[i];

        cout << "Value: " << val ;
        int currentCount = CountInRange(val);
        cout << " Count in Range: "<<currentCount;

        int result = ScaleAndCheck(val, 2);
        cout << " Scale Check: " << result << endl;
    }

    return 0;
}
