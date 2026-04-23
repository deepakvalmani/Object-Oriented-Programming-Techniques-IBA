#include <iostream>
#include <vector>

using namespace std;

int maxVal(const vector<int> &arr, int i = 0)
{
    if (arr.empty()) return -1; // handle empty case

    if (i == arr.size() - 1)
    {
        return arr[i];
    }

    int max_of_rest = maxVal(arr, i + 1);
    return max(arr[i], max_of_rest);
}

bool isSorted(const vector<int> &arr, int i = 0)
{
    if (arr.size() <= 1) return true;

    if (i == arr.size() - 1)
    {
        return true;
    }

    if (arr[i] <= arr[i + 1])
    {
        return isSorted(arr, i + 1);
    }
    else
    {
        return false;
    }
}

void printReverse(const vector<int> &arr, int i = 0)
{
    if (i == arr.size())
    {
        return;
    }
    printReverse(arr, i + 1);
    cout << arr[i] << " ";
}

int countEvens(const vector<int> &arr, int i = 0)
{
    if (i == arr.size())
    {
        return 0;
    }

    return (arr[i] % 2 == 0 ? 1 : 0) + countEvens(arr, i + 1);
}

int main()
{
    vector<int> arr = {3, 7, 1, 9, 4, 6, 2};

    cout << "maximum: " << maxVal(arr) << endl;

    cout << (isSorted(arr) ? "Sorted\n" : "Not Sorted\n");

    cout << "Reverse: ";
    printReverse(arr);

    cout << "\nEven Numbers: " << countEvens(arr) << endl;

    return 0;
}