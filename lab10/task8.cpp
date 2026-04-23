#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>

using namespace std;

auto disturb(vector<int> v, int k)
{
    for (int i = 0; i < k; i++)
    {
        int x = rand() % v.size();
        int y = rand() % v.size();

        swap(v[x], v[y]);
    }
    return v;
}

template <typename T, typename Compare>
pair<vector<T>, int> insertion_sort(vector<T> arr, Compare cmp)
{
    int n = arr.size();
    int cmp_count = 0;

    for (int i = 1; i < n; i++)
    {
        T key = arr[i];
        int j = i - 1;
        while (j >= 0)
        {
            cmp_count++;
            if (cmp(arr[j], key))
            {
                arr[j + 1] = arr[j];
                j--;
            }
            else
            {
                break;
            }
        }
        if (j + 1 != i)
        {
            arr[j + 1] = key;
        }
    }
    return {arr, cmp_count};
}

template <typename T, typename Compare>

pair<vector<T>, int> selection_sort(vector<T> vec, Compare cmp)
{
    int cmp_count = 0;
    for (int i = 0; i < (vec.size() - 1); i++)
    {
        int idx = i;
        for (int j = i + 1; j < vec.size(); j++)
        {
            cmp_count++;
            if (cmp(vec[j], vec[idx]))
            {
                idx = j;
            }
        }
        if (idx != i)
        {
            swap(vec[i], vec[idx]);
        }
    }
    return {vec, cmp_count};
}

int main()
{

    srand(time(0));

    vector<int> nums(1000);

    int n = 1000;
    for (int i = 0; i < n; i++)
    {
        nums[i] = i + 1;
    }
    vector<int> k = {0, 5, 10, 50, 100, 500};

    cout<<"K\t"<<"Insertion\t"<<"Selection\n";

    for (int val : k)
    {
        auto vec = disturb(nums, val);
        auto insert_sorted = insertion_sort(vec, 
            [](int x, int y)
            { return x > y; });
        auto selection_sorted = selection_sort(vec, 
            [](int x, int y)
            { return x < y; });
            
    cout<<val<<"\t"
    <<insert_sorted.second<<"\t\t"
    <<selection_sorted.second<<endl;
        
    }
    return 0;
}
/*Insertion sort performs extremely efficiently on nearly sorted data, requiring only a small number of comparisons when k is low. 
As k increases, the array becomes more disordered, causing the number of comparisons to increase rapidly. 
However, selection sort performs a fixed number of comparisons regardless of input order. 
Thus, insertion sort degrades gradually with increasing disorder, while selection sort remains constant.*/