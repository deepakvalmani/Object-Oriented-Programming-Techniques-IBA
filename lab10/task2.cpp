#include <iostream>
#include <vector>

using namespace std;

void printArray(vector<int> arr)
{
    cout << "[ ";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << "]" << endl;
}

void selection_sort(vector<int> &arr)
{

    for (int i = 0; i < (arr.size() - 1); i++)
    {
        int idx = i;
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[j] > arr[idx])
            {
                idx = j;
            }
        }
        if (idx != i)
        {
            swap(arr[i], arr[idx]);
            cout << "Pass " << i << "( max = " << arr[i] << " placed):";
            printArray(arr);
        }
    }
}
int main()
{

    vector<int> v = {3, 6, 1, 8, 2, 9, 4};
    selection_sort(v);
    printArray(v);

    
    return 0;
}