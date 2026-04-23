#include <iostream>
using namespace std;

template <typename T>

int element_frequency(T arr[], int size, T val)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == val)
            count++;
    }
    return count;
}

int main()
{

    int arr[5] = { 1, 2, 1, 1, 0};
    cout<<element_frequency(arr, 5, 1)<<endl;;

    string str_arr[3] = {"hello", "world", "hello"};
    cout<<element_frequency(str_arr, 3, string("hello"))<<endl;


    return 0;
}