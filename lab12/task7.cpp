#include <iostream>
#include <vector>

using namespace std;

template <typename T, typename Compare>
void merge(vector<T> &arr, int left, int mid, int right, Compare cmp)
{
    vector<T> L(arr.begin() + left, arr.begin() + mid + 1);
    vector<T> R(arr.begin() + mid + 1, arr.begin() + right + 1);

    int i = 0;
    int j = 0;
    int k = left;
    while (i < L.size() && j < R.size())
    {
        if (cmp(L[i], R[j]))
        {
            arr[k++] = L[i++];
        }
        else
        {
            arr[k++] = R[j++];
        }
    }
    while (i < L.size())
    {
        arr[k++] = L[i++];
    }
    while (j < R.size())
    {
        arr[k++] = R[j++];
    }
}

template <typename T, typename Compare>

void merge_sort(vector<T> &arr, int left, int right, Compare cmp)
{
    if (left >= right)
        return;
    int mid = (left + right) / 2;
    merge_sort(arr, left, mid, cmp);
    merge_sort(arr, mid + 1, right, cmp);
    merge(arr, left, mid, right, cmp);
}

int main()
{
    // I int array descending
    vector<int> descending = {1, 2, 4, 7, 2, 3, 13, 15, 27};
    merge_sort(
        descending,
        0,
        descending.size() - 1,
        [](int a, int b)
        { return a > b; });

    for (const int &a : descending)
    {
        cout << a
             << " ";
    }
    cout << endl;

    // II by length ascending
    vector<string> str = {
        "hello",
        "deepak",
        "raj",
        "chatgpt"};
    merge_sort(str,
               0,
               str.size() - 1,
               [](const string &a, const string &b)
               { return a.length() < b.length(); });

    for (const string &a : str)
    {
        cout << a
             << " ";
    }
    cout << endl;

    // III
    vector<pair<int, string>> pair_str = {
        {1, "alright"},
        {6, "byby"},
        {9, "alldone"},
        {4, "wellcome"},
        {9, "wow"}};

    merge_sort(pair_str, 0, pair_str.size() - 1,
               [](const pair<int, string> &a, const pair<int, string> &b)
               {if(a.first != b.first) return a.first < b.first;
                else return a.second < b.second; });

    for (const pair<int, string> &a : pair_str)
    {
        cout << a.first
             << " "
             << a.second
             << endl;
    }
    cout << endl;

    return 0;
}