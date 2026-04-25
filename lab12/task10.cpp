#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>
using namespace std;
using namespace chrono;

// -------- SELECTION SORT --------
void selection_sort(vector<int> &v)
{
    int n = v.size();
    for (int i = 0; i < n - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (v[j] < v[min_idx])
                min_idx = j;
        }
        swap(v[i], v[min_idx]);
    }
}

// -------- INSERTION SORT --------
void insertion_sort(vector<int> &v)
{
    int n = v.size();
    for (int i = 1; i < n; i++)
    {
        int key = v[i];
        int j = i - 1;

        while (j >= 0 && v[j] > key)
        {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = key;
    }
}

// -------- MERGE SORT --------
void merge(vector<int> &v, int l, int m, int r)
{
    vector<int> L(v.begin() + l, v.begin() + m + 1);
    vector<int> R(v.begin() + m + 1, v.begin() + r + 1);

    int i = 0, j = 0, k = l;

    while (i < L.size() && j < R.size())
    {
        if (L[i] < R[j])
            v[k++] = L[i++];
        else
            v[k++] = R[j++];
    }

    while (i < L.size())
        v[k++] = L[i++];
    while (j < R.size())
        v[k++] = R[j++];
}

void merge_sort(vector<int> &v, int l, int r)
{
    if (l >= r)
        return;
    int m = (l + r) / 2;
    merge_sort(v, l, m);
    merge_sort(v, m + 1, r);
    merge(v, l, m, r);
}

// QUICK SORT
int partition(vector<int> &v, int l, int r)
{
    int pivot = v[r];
    int i = l - 1;

    for (int j = l; j < r; j++)
    {
        if (v[j] < pivot)
        {
            i++;
            swap(v[i], v[j]);
        }
    }
    swap(v[i + 1], v[r]);
    return i + 1;
}

void quick_sort(vector<int> &v, int l, int r)
{
    if (l >= r)
        return;
    int pi = partition(v, l, r);
    quick_sort(v, l, pi - 1);
    quick_sort(v, pi + 1, r);
}

// RANDOM ARRAY
vector<int> generate_random(int n)
{
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        v[i] = rand() % 100000;
    return v;
}

//  TIME FUNCTION
long long measure(void (*sort_func)(vector<int> &), vector<int> arr)
{
    auto start = high_resolution_clock::now();
    sort_func(arr);
    auto end = high_resolution_clock::now();
    return duration_cast<milliseconds>(end - start).count();
}

// Wrapper for merge & quick
long long measure_merge(vector<int> arr)
{
    auto start = high_resolution_clock::now();
    merge_sort(arr, 0, arr.size() - 1);
    auto end = high_resolution_clock::now();
    return duration_cast<milliseconds>(end - start).count();
}

long long measure_quick(vector<int> arr)
{
    auto start = high_resolution_clock::now();
    quick_sort(arr, 0, arr.size() - 1);
    auto end = high_resolution_clock::now();
    return duration_cast<milliseconds>(end - start).count();
}

int main()
{
    srand(time(0));

    vector<int> sizes = {100, 1000, 10000};

    cout << "n\tSelection\tInsertion\tMerge\tQuick\n";

    for (int n : sizes)
    {
        vector<int> base = generate_random(n);

        vector<int> a = base, b = base, c = base, d = base;

        long long t1 = measure(selection_sort, a);
        long long t2 = measure(insertion_sort, b);
        long long t3 = measure_merge(c);
        long long t4 = measure_quick(d);

        cout << n << "\t"
             << t1 << "ms\t\t"
             << t2 << "ms\t\t"
             << t3 << "ms\t"
             << t4 << "ms\n";
    }

    return 0;
}