#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &v, int left, int mid, int right)
{
    vector<int> L(v.begin() + left, v.begin() + mid + 1);
    vector<int> R(v.begin() + mid + 1, v.begin() + right + 1);

    int i = 0;
    int j = 0;
    int k = left;
    while (i < L.size() && j < R.size())
    {
        if (L[i] < R[j])
        {
            v[k++] = L[i++];
        }
        else
        {
            v[k++] = R[j++];
        }
    }
    while (i < L.size())
    {
        v[k++] = L[i++];
    }

    while (j < R.size())
    {
        v[k++] = R[j++];
    }
}

void merge_sort(vector<int> &v, int left, int right)
{
    if (left >= right)
        return;

    int mid = (left + right) / 2;
    merge_sort(v, left, mid);
    merge_sort(v, mid + 1, right);

    merge(v, left, mid, right);
}

int heightChecker(const vector<int> &heights)
{
    vector<int> sorted_heights(heights.begin() + 0, heights.begin() + heights.size());
    merge_sort(sorted_heights, 0, sorted_heights.size() - 1);

    int count = 0;
    for (int i = 0; i < sorted_heights.size(); i++)
    {
        if (sorted_heights[i] != heights[i])
        {
            count++;
        }
    }
    return count;
}

int main()
{
    std::vector<int> h1 = {1, 1, 4, 2, 1, 3};
    std::cout << "Test 1: " << heightChecker(h1)
              << " (expected 3)" << std::endl;
    std::vector<int> h2 = {5, 1, 2, 3, 4};
    std::cout << "Test 2: " << heightChecker(h2)
              << " (expected 5)" << std::endl;
    std::vector<int> h3 = {1, 2, 3, 4, 5};
    std::cout << "Test 3: " << heightChecker(h3)
              << " (expected 0)" << std::endl;
    std::vector<int> h4 = {3, 3, 3, 3};
    std::cout << "Test 4: " << heightChecker(h4)
              << " (expected 0)" << std::endl;
    std::vector<int> h5 = {2, 1};
    std::cout << "Test 5: " << heightChecker(h5)
              << " (expected 2)" << std::endl;
    return 0;
}
