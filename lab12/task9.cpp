#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

int comp_count = 0;

// INSERTION SORT
void insertion_sort(vector<int> &v, int left, int right)
{
    for (int i = left + 1; i <= right; i++)
    {
        int key = v[i];
        int j = i - 1;

        while (j >= left)
        {
            comp_count++;
            if (v[j] > key)
            {
                v[j + 1] = v[j];
                j--;
            }
            else
                break;
        }
        v[j + 1] = key;
    }
}

// MEDIAN OF THREE
int median_of_three(vector<int> &v, int a, int b, int c)
{
    comp_count++;
    if ((v[a] > v[b]) != (v[a] > v[c]))
        return a;
    comp_count++;
    if ((v[b] > v[a]) != (v[b] > v[c]))
        return b;
    return c;
}

//  PARTITION
int partition(vector<int> &v, int left, int right)
{
    int mid = left + (right - left) / 2;
    int pivotIndex = median_of_three(v, left, mid, right);

    swap(v[pivotIndex], v[right]);
    int pivot = v[right];

    int i = left - 1;

    for (int j = left; j < right; j++)
    {
        comp_count++;
        if (v[j] < pivot)
        {
            i++;
            swap(v[i], v[j]);
        }
    }

    swap(v[i + 1], v[right]);
    return i + 1;
}

//  HYBRID SORT
void hybrid_sort(vector<int> &v, int left, int right, int k)
{
    if (right - left + 1 <= k)
    {
        insertion_sort(v, left, right);
        return;
    }

    int pi = partition(v, left, right);
    hybrid_sort(v, left, pi - 1, k);
    hybrid_sort(v, pi + 1, right, k);
}

//  GENERATE RANDOM ARRAY
vector<int> generate_random(int n)
{
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        v[i] = rand() % 10000;
    return v;
}

int main()
{
    srand(time(0));

    vector<int> sizes = {50, 200, 1000};
    vector<int> ks = {5, 10, 20};

    for (int n : sizes)
    {
        cout << "\nArray size n = " << n << endl;

        for (int k : ks)
        {
            vector<int> arr = generate_random(n);

            comp_count = 0;
            hybrid_sort(arr, 0, arr.size() - 1, k);

            cout << "k = " << k
                 << " Comparisons: " << comp_count << endl;
        }
    }

    return 0;
}
/* 
The hybrid algorithm uses Quick Sort for large subarrays and switches
to Insertion Sort when the subarray size becomes small ≤ k

Experimental results show that k ≈ 10 gives the minimum comparisons

This is because Insertion Sort is more efficient for small arrays due
to lower overhead and better cache performance, while Quick Sort is
efficient for larger partitions.

Thus combining both improves overall performance.

*/