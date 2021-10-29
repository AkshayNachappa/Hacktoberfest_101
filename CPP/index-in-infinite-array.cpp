#include<iostream>
using namespace std;
#include<vector>

int binarysearch(vector<int> arr, int target, int start,int end)
{
    while(start<=end)
    {
        int mid= start+(end-start)/2;
            if(target< arr[mid])
                end= mid-1;
            else if(target> arr[mid])
                start=mid+1;
            else
            return mid;

            
    }
}

int ans(vector<int> arr, int target)
{
    int s=0;
    int e=1;
    int newstart;
       while(target > e)
       {
            newstart= e+1;
           e=e+(e-s+1)*2;
        }
        return (binarysearch( arr,  target, newstart ,e));
}



int main()
{
    vector <int> vec; int x,target;
    cout<<"enter array";
    for(int i=0;i<10;i++)
    {
        cin>>x;
        vec.push_back(x);

    }
    cout<<"target";
    cin>>target;
    cout<<ans(vec,  target);

}