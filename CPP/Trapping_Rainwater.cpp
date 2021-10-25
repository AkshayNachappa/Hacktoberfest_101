//We are given 'n' non-negative numbers, which represet an elevation map where 
//the width of each bar is equal to 1. We are required to find how much water 
//would be trapped after raining.

#include <bits/stdc++.h>
using namespace std;
 
int findWater(int arr[], int n)
{
    int left[n];                    //height of tallest bar to left of ith bar
 
    int right[n];                   //height of tallest bar to left of ith bar
 
    int water = 0;
 
    left[0] = arr[0];
    for (int i = 1; i < n; i++)
        left[i] = max(left[i - 1], arr[i]);
 
    right[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
        right[i] = max(right[i + 1], arr[i]);
 
    for (int i = 0; i < n; i++)
        water += min(left[i], right[i]) - arr[i];
 
    return water;
}

int main()
{
    int n;
    cin>>n;
    int arr[n],i;
    for(i=0;i<n;i++)
        cin>>arr[i];
    cout<<"Maximum rainwater that would be trapped is: "<<findWater(arr, n);
    return 0;
}




//Time and space Complexities: O(n)