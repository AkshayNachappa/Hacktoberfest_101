#include<iostream>
using namespace std;

void binSearch(int arr[],int N,int x)
{
    int i;
    int left = 0;
    int right = N-1;
    int mid = (N-1)/2;
    while(left<right)
    {
        if(x==arr[mid])
        {
            cout<<"The number "<<x<<" found at "<<mid+1<<endl;
            break;
        }
        else if(x<arr[mid])
        {
            
            right =  mid;
            left =0;
            mid = (left + right)/2;            

        }
        else
        {
            right =  (N-1);
            left =mid;
            mid = (left + right)/2; 
        }
    }

}
int* sort(int arr[],int N)
{
    for(int i=0;i<N;i++)
    {
        for(int j=i+1;j<N;j++)
        {
            if(arr[i]>arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    return arr;
}
int main()
{
    int N,x;
    cout <<"Enter the size of the array and the no. to be searched \n";
    cin>>N>>x;
    int *arr = new int[N];
    cout<<"Enter the array \n";
    for(int i=0;i<N;i++)
    {
        cin>>arr[i];
    }
    int* ptr = sort(arr,N);
    cout<<"Sorted array: ";
    for(int i=0;i<N;i++)
    {
        cout<<ptr[i]<<" ";
    }
    cout<<endl;
    binSearch(ptr,N,x);
    return 0;
}