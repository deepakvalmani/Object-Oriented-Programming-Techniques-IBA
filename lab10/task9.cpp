#include <iostream>
#include <vector>

using namespace std;

struct Student
{
    string name;
    double gpa;
    int year;
};

template <typename T, typename Compare>
auto insertion_sort(vector<T> arr, Compare cmp)
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
    return arr;
}

template <typename T, typename Compare>
auto selection_sort(vector<T> vec, Compare cmp)
{
    for (int i = 0; i < (vec.size() - 1); i++)
    {
        int idx = i;
        for (int j = i + 1; j < vec.size(); j++)
        {
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
    return vec;
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

void print(Student s)
{
    cout << s.name << "\t"
         << s.gpa << "\t"
         << s.year << endl;
}

int main()
{
    vector<Student> list = {
        {"deepu", 3.99, 2025},
        {"laksh", 4, 2024},
        {"Alex", 2.3, 2020},
        {"hamza", 1.5, 2020}};

    // Sorting on GPA
    auto gpa_insertion_sorted = insertion_sort(list, 
        [](Student a, Student b)
        { return a.gpa < b.gpa; });
    auto gpa_selection_sorted = selection_sort(list, 
        [](Student a, Student b)
        { return a.gpa > b.gpa; });

    

    cout << "Insertion Sorted on GPA (highest first)\n";

    print_vec(gpa_insertion_sorted, 
        [](Student s)
        { print(s); });

    cout << "Selection Sorted on GPA (highest first)\n";

    print_vec(gpa_selection_sorted, 
        [](Student s)
        { print(s); });

    // Sorting on Year ascending, then GPA descending (two-key sort)

    auto year_gpa_insertion_sorted = insertion_sort(list, 
        [](Student a, Student b)
        { if(a.year != b.year){
        return a.year >b.year;}                                                
        return a.gpa < b.gpa; });

    auto year_gpa_selection_sorted = selection_sort(list, 
        [](Student a, Student b)
        { if(a.year != b.year){
        return a.year < b.year;}
        return a.gpa > b.gpa; });

    cout << "Insertion Sorted on Year ascending, then GPA descending (two-key sort)\n";

    print_vec(year_gpa_insertion_sorted, 
        [](Student s)
        { print(s); });

    cout << "Selection Sorted on Year ascending, then GPA descending (two-key sort)\n";

    print_vec(year_gpa_selection_sorted, 
        [](Student s)
        { print(s); });

    // Sorting on Name alphabetically ascending.
    auto name_insertion_sorted = insertion_sort(list, 
        [](Student a, Student b)
        { return a.name > b.name; });
    auto name_selection_sorted = selection_sort(list, 
        [](Student a, Student b)
        { return a.name < b.name; });

    cout << "Insertion Sorted on Name alphabetically ascending.\n";

    print_vec(name_insertion_sorted, 
        [](Student s)
        { print(s); });
    cout << "Selection Sorted on Name alphabetically ascending.\n";
    
    print_vec(name_selection_sorted, 
        [](Student s)
        { print(s); });

    return 0;
}