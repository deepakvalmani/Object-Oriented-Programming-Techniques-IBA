#include <iostream>
#include <vector>

using namespace std;

template <typename T, typename Compare>
void insertionSort(vector<T> &arr, Compare cmp)
{
    int n = arr.size();

    for (int i = 1; i < n; i++)
    {
        T key = arr[i];
        int j = i - 1;
        while (j >= 0)
        {
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
}

template <typename T, typename fun>
void print_vec(vector<T> &v, fun f)
{
    for (T val : v)
    {
        f(val);
    }
    cout << endl;
}
int main()
{
    vector<int> nums = {11, 21, 3, 75, 4, 12, 23, 45, 43, 67};
    // sorting a vector int in ascending order
    cout << "Before sorting: \n";
    print_vec(nums, [](int a){ cout << a << " "; });
    insertionSort(nums, [](int a, int b){ return (a > b); });
    cout << "Vector int in ascending order:\n";
    print_vec(nums, [](int a){ cout << a << " "; });

    vector<string> strings = {"Hello", "By", "Deepu", "Good"};

    cout << "Before sorting: \n";
    print_vec(strings, [](string s){ cout << string(s) << " "; });
    insertionSort(strings, [](string s1, string s2){ return (s1 < s2); });
    cout << "after sorting: \n";
    print_vec(strings, [](string s){ cout << string(s) << " "; });

    vector<pair<int, string>> pair_vec = {
        {3, "Hello"},
        {1, "World"},
        {3, "Apple"},
        {2, "Deepu"}};

    insertionSort(
        pair_vec, 
        [](const pair<int, string> &a, const pair<int, string> &b){
        if (a.first != b.first) {
        return a.first > b.first;
        }
    return a.second > b.second; });

    cout << "Pairs (Int Asc, String Asc): \n";
    print_vec(pair_vec, [](pair<int, string> p){ cout << "{" << p.first << ", " << p.second << "} "; });

    return 0;
}