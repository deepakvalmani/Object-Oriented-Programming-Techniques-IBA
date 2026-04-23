#include <iostream>
#include<algorithm>
#include<array>


using namespace std;

void printArray(int arr[], int size){
    cout<<"[ ";
    for(int i = 0; i < size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<"]"<<endl;
}

void selection_sort(int arr[], int size)
{

    for (int i = 0; i < size - 1; i++)
    {
        int idx  = i;
        for(int j = i +1;j < size; j++ ){
            if(arr[j] < arr[idx]){
                idx = j;
            }
        }
        if (idx != i){
            swap(arr[i], arr[idx]);
            cout<<"Pass "<<i << "( min = "<< arr[i]<<" placed):";
            printArray(arr, size);
        }

        
    }
}

int main()
{
    int arr[] = {29, 10, 14, 37, 13};
    selection_sort(arr, 5);
    printArray(arr, 5);

    return 0;
}