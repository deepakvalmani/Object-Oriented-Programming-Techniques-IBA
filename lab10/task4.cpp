#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// Standard Insertion Sort
int insertion_sort(vector<int> arr)
{
    int comp = 0;

    for (int i = 1; i < arr.size(); i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0)
        {
            comp++;
            if (arr[j] > key)
            {
                arr[j + 1] = arr[j];
                j--;
            }
            else
                break;
        }
        arr[j + 1] = key;
    }
    return comp;
}

// Binary Insertion Sort
int binary_insertion_sort(vector<int> arr)
{
    int comp = 0;

    for (int i = 1; i < arr.size(); i++)
    {
        int key = arr[i];

        // Binary search using lower_bound
        auto pos = lower_bound(arr.begin(), arr.begin() + i, key);

        // Count comparisons (approx log2(i))
        comp += log2(i + 1);

        // Shift elements
        for (auto j = arr.begin() + i; j > pos; j--)
        {
            *j = *(j - 1);
        }

        *pos = key;
    }

    return comp;
}

int main()
{
    vector<int> arr = {12, 5, 8, 3, 15, 7, 1, 10, 6, 14,
                       2, 9, 4, 11, 13, 16, 18, 17, 19, 20};

    vector<int> a1 = arr;
    vector<int> a2 = arr;

    int normal_comp = insertion_sort(a1);
    int binary_comp = binary_insertion_sort(a2);

    cout << "Standard Insertion Sort Comparisons: " << normal_comp << endl;
    cout << "Binary Insertion Sort Comparisons: " << binary_comp << endl;

    return 0;
}

/*
Even though binary insertion sort uses binary search to find the correct position in O(log n) time, 
the overall time complexity remains O(n^2). This is because, after finding the correct position, 
the algorithm still needs to shift elements to make space for insertion.

In the worst case, for each element, up to n elements may need to be shifted. 
Since this shifting happens for each of the n elements, the total cost of shifting becomes O(n²). 
This dominates the overall running time.

Therefore, while binary search reduces the number of comparisons, it does not reduce the number of shifts. 
As a result, the overall time complexity of binary insertion sort remains O(n^2).
*/