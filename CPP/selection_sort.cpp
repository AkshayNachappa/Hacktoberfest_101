#include <bits/stdc++.h>
using namespace std;

int mx(vector<int> arr, int e)
{
    int m = 0;
    for (int i = 0; i <= e; i++)
    {
        if (arr[i] > arr[m])
        {
            m = i;
        }
    }
    return m;
}

void swap(int &a,int &b){
    int temp =a;
    a=b;
    b=temp;
}

void selectionSort(vector<int> &arr)
{

    for (int i = 0; i < arr.size(); i++)
    {
        int m = mx(arr,arr.size()-1-i);
        swap(arr[m],arr[arr.size()-1-i]);
    }
    for (int i = 0; i < arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }
    
}

int main()
{

    vector<int>arr={5,3,4,2,1};
    bubbleSort(arr);
    return 0;
}
