#include <iostream>
#include<vector>

using namespace std;
struct Student
{
    string name;
    double gpa;
    int year;
};

void print(const vector<Student> &v)
{
    for (const auto &s : v)
        cout << s.name << "\t" << s.gpa << "\t" << s.year << endl;
    cout << endl;
}

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

template <typename T, typename Compare>

int partition(vector<T> &v, int st, int end, Compare cmp)
{
    T pivot = v[end];
    int i = st - 1;

    for (int j = st; j < end; j++)
    {
        if (cmp(v[j] , pivot))
        {
            i++;
            swap(v[i], v[j]);
        }
    }

    swap(v[i + 1], v[end]);
    return i + 1;
}
template <typename T, typename Compare>

void quick_sort(vector<T> &v, int st, int end, Compare cmp)
{
    if (st >= end)
        return;

    int pi = partition(v, st, end, cmp);
    quick_sort(v, st, pi - 1, cmp);
    quick_sort(v, pi + 1, end, cmp);
}
int main()
{
    vector<Student> students = {
        {"Ali", 3.5, 2},
        {"Sara", 3.8, 1},
        {"John", 3.5, 3},
        {"Zara", 3.8, 2},
        {"Ahmed", 3.5, 2}
    };

    // I GPA descending
    auto gpa_desc = [](const Student &a, const Student &b)
    {
        return a.gpa > b.gpa;
    };

    vector<Student> m1 = students, q1 = students;

    merge_sort(m1, 0, m1.size() - 1, gpa_desc);
    quick_sort(q1, 0, q1.size() - 1, gpa_desc);

    cout << "Merge Sort GPA desc:\n";
    print(m1);

    cout << "Quick Sort GPA desc:\n";
    print(q1);

    // II year asc, GPA desc 
    auto year_gpa = [](const Student &a, const Student &b)
    {
        if (a.year != b.year) return a.year < b.year;
        return a.gpa > b.gpa;
    };

    vector<Student> m2 = students, q2 = students;

    merge_sort(m2, 0, m2.size() - 1, year_gpa);
    quick_sort(q2, 0, q2.size() - 1, year_gpa);

    cout << "Merge Sort Year asc, GPA desc:\n";
    print(m2);

    cout << "Quick Sort Year asc, GPA desc:\n";
    print(q2);

    // III name ascending 
    auto name_asc = [](const Student &a, const Student &b)
    {
        return a.name < b.name;
    };

    vector<Student> m3 = students, q3 = students;

    merge_sort(m3, 0, m3.size() - 1, name_asc);
    quick_sort(q3, 0, q3.size() - 1, name_asc);

    cout << "Merge Sort Name asc:\n";
    print(m3);

    cout << "Quick Sort Name asc:\n";
    print(q3);

    return 0;
}