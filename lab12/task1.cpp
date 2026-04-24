#include <iostream>
#include <vector>
using namespace std;
// normal print
void print(vector<int> &v)
{
    for (int val : v)
    {
        cout << val << " ";
    }
    cout << endl;
}
// Print when start and end are given
void print1(vector<int> &v, int st, int end)
{
    while (st <= end)
    {
        cout << v[st] << " ";
        st++;
    }
    cout << endl;
}

void merge(vector<int> &v, int left, int mid, int right)
{
    vector<int> L(v.begin() + left, v.begin() + mid + 1);
    vector<int> R(v.begin() + mid + 1, v.begin() + right + 1);
    // Print left and right array
    cout << "left array: ";
    print(L);
    cout << "right array: ";
    print(R);

    int i = 0;
    int j = 0;
    int k = left;
    while (i < int(L.size()) && j < int(R.size()))
    {
        if (L[i] < R[j])
        {
            v[k++] = L[i++];
        }
        else
        {
            v[k++] = R[j++];
        }
    }
    while (i < int(L.size()))
    {
        v[k++] = L[i++];
    }
    while (j < int(R.size()))
    {
        v[k++] = R[j++];
    }
}

void merge_sort(vector<int> &v, int st, int end)
{

    if (st >= end)
    {
        return;
    }
    // Print the array on which the merge_sort has been called
    cout << "calling: ";
    print1(v, st, end);
    int mid = st + (end - st) / 2;
    merge_sort(v, st, mid);
    merge_sort(v, mid + 1, end);
    merge(v, st, mid, end);
}

int main()
{
    vector<int> arr = {38, 27, 43, 3, 9};
    print(arr);
    merge_sort(arr, 0, arr.size() - 1);

    print(arr);

    return 0;
}

/*
program output:

calling: 38 27 43 3 9 
calling: 38 27 43 
calling: 38 27 
left array: 38 
right array: 27 
left array: 27 38 
right array: 43 
calling: 3 9 
left array: 3 
right array: 9 
left array: 27 38 43 
right array: 3 9 
3 9 27 38 43 
*/