#include <iostream>
#include <vector>

using namespace std;

void print_vec(vector<int> v){
    for(int val: v){
        cout<<val<<" ";
    }
    cout<<endl;
}

void InsertionSort(vector<int> &v)
{
    int n = v.size();

    for (int i = 0; i < n; i++)
    {
        int key = v[i];
        int j = i - 1;
        while (j >= 0 && v[j] > key)
        {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = key;
        cout<<"vector at i = "<<i<<" : ";
        print_vec(v);

    }
}

int main()
{
    vector<int> vec = {8, 3, 7, 1, 5};
    InsertionSort(vec);
    cout<<"vector after sorting: ";
    print_vec(vec);


    return 0;
}