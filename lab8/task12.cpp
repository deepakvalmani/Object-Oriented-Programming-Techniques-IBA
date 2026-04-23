#include <iostream>
#include <algorithm>

using namespace std;

template <typename T>

void sort_array(T arr[], int size)
{
    sort(arr, arr + size);
}

template <typename T>

void reverse_array(T arr[], int size)
{
    reverse(arr, arr + size);
}

template <typename T>
int binary_search(T arr[], int size, T target)
{
    int st = 0;
    int end = size - 1;
    sort_array(arr, size);
    while (st <= end)
    {
        int mid = (st + end) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        if (arr[mid] < target)
        {
            st = mid  + 1;
        }
        if (arr[mid] > target)
        {
            end = mid +-1;
        }
    }
    return -1;
}

int main()
{
    int arr[3] = {2, 3, 1};

    sort_array(arr, 3);
    // printing array after sorting
    for (int val : arr)
    {
        cout << val << " ";
    }
    cout << endl;

    reverse_array(arr, 3);
    // printing array after reverse
    for (int val : arr)
    {
        cout << val << " ";
    }
    cout << endl;

    // binarry search 
    cout<<binary_search(arr, 3, 1)<<endl;


    return 0;
}