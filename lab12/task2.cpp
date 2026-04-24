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

int comp_count = 0;
void merge(vector<int> &v, int left, int mid, int right)
{
    vector<int> L(v.begin() + left, v.begin() + mid + 1);
    vector<int> R(v.begin() + mid + 1, v.begin() + right + 1);

    int i = 0;
    int j = 0;
    int k = left;
    while (i < int(L.size()) && j < int(R.size()))
    {
        comp_count++;
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

    int mid = st + (end - st) / 2;
    merge_sort(v, st, mid);
    merge_sort(v, mid + 1, end);
    merge(v, st, mid, end);
}

int main()
{
    vector<int> sorted = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    vector<int> reverse_sorted = {16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    vector<int> random = {7, 2, 14, 9, 1, 5, 11, 3, 6, 10, 4, 8, 13, 15, 12, 16};

    print(sorted);
    merge_sort(sorted, 0, sorted.size() - 1);
    cout << "Sorted Comp count: " << comp_count << endl;

    comp_count =0;
    print(reverse_sorted);
    merge_sort(reverse_sorted, 0, reverse_sorted.size() - 1);
    cout << "Reverse Sorted Comp count: " << comp_count << endl;
    comp_count =0;
    print(random);
    merge_sort(random, 0, random.size() - 1);
    cout << "Random Comp count: " << comp_count << endl;

    return 0;
}

/*
Sorted Comp count: 32
Reverse Sorted Comp count: 32
Random Comp count: 44

this is the nummber of comp made for each of the input
although the number is not exactly same but it is in the same range or same order of grougth
This confirms that Merge Sort has a time complexity of 
O(n log(n))

*/
