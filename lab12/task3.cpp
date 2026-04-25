#include <iostream>
#include <vector>
using namespace std;

struct Card
{
    int value;
    char suit;
};

void print(vector<Card> &v)
{
    for (Card val : v)
    {
        cout << val.value << " " << val.suit << endl;
    }
    cout << endl;
}

void merge(vector<Card> &v, int left, int mid, int right)
{
    vector<Card> L(v.begin() + left, v.begin() + mid + 1);
    vector<Card> R(v.begin() + mid + 1, v.begin() + right + 1);
    int i = 0;
    int j = 0;
    int k = left;
    while (i < int(L.size()) && j < int(R.size()))
    {
        if (L[i].value <= R[j].value)
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

void merge_sort(vector<Card> &v, int st, int end)
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

int partition(vector<Card> &v, int st, int end)
{
    Card pivot = v[end];
    int i = st - 1;
    for (int j = st; j < end; j++)
    {
        if (v[j].value <= pivot.value)
        {
            i++;
            swap(v[i], v[j]);
        }
    }
    swap(v[i + 1], v[end]);
    return i + 1;
}

void quick_sort(vector<Card> &v, int st, int end)
{
    if (st >= end)
    {
        return;
    }
    int pi = partition(v, st, end);
    quick_sort(v, st, pi - 1);
    quick_sort(v, pi + 1, end);
}

int main()
{
    vector<Card> cards1 = {
        {2, 'A'},
        {1, 'X'},
        {2, 'B'},
        {1, 'Y'}};

    vector<Card> cards2 = {
        {2, 'A'},
        {1, 'X'},
        {2, 'B'},
        {1, 'Y'}};

    merge_sort(cards1, 0, cards1.size() - 1);
    quick_sort(cards2, 0, cards2.size() - 1);
    cout << "Merge Sort: \n";
    print(cards1);
    cout << "Quick Sort: \n";
    print(cards2);
}

// Stability Test
// Merge Sort preserves the relative order of elements with equal values
// In the output, (2,A) appears before (2,B), same as in the original array
// so Merge Sort is stable.
//
// Quick Sort (Lomuto partition) does not guarantee stability
// In the output, (2,B) appears before (2,A), which changes the original order
// so Quick Sort is not stable.
