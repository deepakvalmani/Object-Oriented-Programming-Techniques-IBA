#include <iostream>
#include <vector>

using namespace std;
// normal print
void print(vector<int> &v)
{
    for (int val : v)
    {
        cout << val
             << " ";
    }
    cout << endl;
}
// Print when start and end are given
void print1(vector<int> &v, int st, int end)
{
    while (st <= end)
    {
        cout << v[st]
             << " ";
        st++;
    }
    cout << endl;
}

int partition(vector<int> &v, int st, int end)
{
    int pivot = v[end];
    int i = st - 1;
    for (int j = st; j < end; j++)
    {
        if (v[j] < pivot)
        {
            i++;
            swap(v[i], v[j]);
            cout << "after swap: ";
            print(v);
        }
    }
    swap(v[i + 1], v[end]);
    // printing array after swap
    cout << "after swap: ";
    print(v);

    // print pivot and positoin of pivot;
    cout << "current pivot: "
         << pivot
         << " \n"
         << "pivot position: "
         << i + 1
         << endl;

    return i + 1;
}

void quick_sort(vector<int> &v, int st, int end)
{

    if (st >= end)
    {
        return;
    }
    // print array on which the quick sort function has been called
    cout << "Calling: ";
    print1(v, st, end);
    int pi = partition(v, st, end);
    quick_sort(v, st, pi - 1);
    quick_sort(v, pi + 1, end);
}
int main()

{
    vector<int> arr = {8, 3, 7, 1, 5, 2, 4};

    cout << "Original Array: ";
    print(arr);
    cout << endl;

    quick_sort(arr, 0, arr.size() - 1);

    cout << "\nSorted Array: ";
    print(arr);

    return 0;
}

/*

Calling: 8 3 7 1 5 2 4 
after swap: 3 8 7 1 5 2 4 
after swap: 3 1 7 8 5 2 4 
after swap: 3 1 2 8 5 7 4 
after swap: 3 1 2 4 5 7 8 
current pivot: 4 
pivot position: 3
Calling: 3 1 2 
after swap: 1 3 2 4 5 7 8 
after swap: 1 2 3 4 5 7 8 
current pivot: 2 
pivot position: 1
Calling: 5 7 8 
after swap: 1 2 3 4 5 7 8 
after swap: 1 2 3 4 5 7 8 
after swap: 1 2 3 4 5 7 8 
current pivot: 8 
pivot position: 6
Calling: 5 7 
after swap: 1 2 3 4 5 7 8 
after swap: 1 2 3 4 5 7 8 
current pivot: 7 
pivot position: 5

Sorted Array: 1 2 3 4 5 7 8 

*/