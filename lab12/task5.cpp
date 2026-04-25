#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int comp_count = 0;

int partition_last(vector<int> &v, int st, int end)
{
    int pivot = v[end];
    int i = st - 1;

    for (int j = st; j < end; j++)
    {
        comp_count++;
        if (v[j] < pivot)
        {
            i++;
            swap(v[i], v[j]);
        }
    }

    swap(v[i + 1], v[end]);
    return i + 1;
}

void quick_sort_last(vector<int> &v, int st, int end)
{
    if (st >= end)
        return;

    int pi = partition_last(v, st, end);
    quick_sort_last(v, st, pi - 1);
    quick_sort_last(v, pi + 1, end);
}

int partition_rand(vector<int> &v, int st, int end)
{
    int pivotIndex = st + rand() % (end - st + 1);
    swap(v[pivotIndex], v[end]);
    int pivot = v[end];
    int i = st - 1;

    for (int j = st; j < end; j++)
    {
        comp_count++;
        if (v[j] < pivot)
        {
            i++;
            swap(v[i], v[j]);
        }
    }
    swap(v[i + 1], v[end]);
    return i + 1;
}

void quick_sort_rand(vector<int> &v, int st, int end)
{
    if (st >= end)
        return;

    int pi = partition_rand(v, st, end);
    quick_sort_rand(v, st, pi - 1);
    quick_sort_rand(v, pi + 1, end);
}

int main()
{
    srand(time(0));

    vector<int> sorted = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

    vector<int> copy = sorted;

    // Last element pivot
    quick_sort_last(sorted, 0, sorted.size() - 1);
    cout << "Last pivot comp count: " << comp_count << endl;

    comp_count = 0;

    // Random pivot
    quick_sort_rand(copy, 0, copy.size() - 1);
    cout << "Random pivot comp count: " << comp_count << endl;

    return 0;
}
/*

Quick Sort Worst Case Demonstration:

For a sorted array of size n = 15, using the last element as pivot,
the number of comparisons observed is 105.

This matches the theoretical worst-case formula:
n(n-1)/2 = 15*14/2 = 105, confirming O(n^2) behavior.

When switching to a random pivot, the number of comparisons
drops significantly (around 50–70), which is close to O(n log n).

This shows that Quick Sort's performance is highly dependent
on pivot selection. A poor pivot leads to worst-case performance,
while a randomized pivot helps achieve average-case efficiency.

*/