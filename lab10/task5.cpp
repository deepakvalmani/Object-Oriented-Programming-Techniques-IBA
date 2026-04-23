#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print_vec(vector<int> &v)
{
    for (int val : v)
    {
        cout << val << " ";
    }
    cout << endl;
}

void selection_sort_desc(vector<int> vec)
{
    int swap_count = 0;
    int comp_count = 0;
    for (int i = 0; i < (vec.size() - 1); i++)
    {
        int idx = i;
        for (int j = i + 1; j < vec.size(); j++)
        {
            comp_count++;
            if (vec[j] > vec[idx])
            {
                idx = j;
            }
        }
        if (idx != i)
        {
            swap(vec[i], vec[idx]);
            swap_count++;
        }
    }
    cout << "swap count = " << swap_count << endl;
    cout << "comparision cout = " << comp_count << endl;
}

void selection_sort_asc(vector<int> vec)
{
    int swap_count = 0;
    int comp_count = 0;
    for (int i = 0; i < (vec.size() - 1); i++)
    {
        int idx = i;
        for (int j = i + 1; j < vec.size(); j++)
        {
            comp_count++;
            if (vec[j] < vec[idx])
            {
                idx = j;
            }
        }
        if (idx != i)
        {
            swap(vec[i], vec[idx]);
            swap_count++;
        }
    }

    cout << "swap count = " << swap_count << endl;
    cout << "comparision cout = " << comp_count << endl;
}

void InsertionSort(vector<int> v)
{
    int n = v.size();
    int swap_count = 0;
    int comp_count = 0;

    for (int i = 1; i < n; i++)
    {
        int key = v[i];
        int j = i - 1;
        while (j >= 0)
        {
            comp_count++;
            if (v[j] > key)
            {
                v[j + 1] = v[j];
                j--;
            }
            else{
                break;
            }
        }
        if (j + 1 != i)
        {
            v[j + 1] = key;
            swap_count++;
        }
    }
    cout << "swap count = " << swap_count << endl;
    cout << "comparision cout = " << comp_count << endl;
}

int main()
{
    vector<int> v1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    vector<int> v2 = {15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    vector<int> v = {5, 12, 3, 9, 1, 14, 7, 2, 11, 6, 15, 4, 8, 10, 13};

    cout << "sorted: " << endl;
    cout << "Selection Sort: \n";
    selection_sort_asc(v1);
    cout << "insertion Sort: \n";
    InsertionSort(v1);

    cout << "\nDescending sorted: " << endl;
    cout << "Selection Sort: \n";
    selection_sort_asc(v2);
    cout << "insertion Sort: \n";
    InsertionSort(v2);

    cout << "\nUnsorted: " << endl;
    cout << "Selection Sort: \n";
    selection_sort_asc(v);
    cout << "insertion Sort: \n";
    InsertionSort(v);
    return 0;
}

/*
sorted: 
Selection Sort:
swap count = 0
comparision cout = 105
insertion Sort:
swap count = 0
comparision cout = 14

Descending sorted:
Selection Sort:
swap count = 7
comparision cout = 105
insertion Sort:
swap count = 14
comparision cout = 105

Unsorted:
Selection Sort:
swap count = 10
comparision cout = 105
insertion Sort:
swap count = 11
comparision cout = 54

The results mostly match theoretical predictions. 
Selection sort always performs 105 comparisons regardless of input, showing it is not adaptive. 
Insertion sort varies with input: it performs best on sorted data and worst on reverse sorted data.

*/
