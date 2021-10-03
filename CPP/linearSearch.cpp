#include<iostream>
using namespace std;

void search(int a[],int N, int n)
{
    int count=0;
    
    for(int i=0;i<N;i++)
    {
        if(a[i]==n)
         {
            cout <<"The number "<<n<<" occured at index"<<i+1<<endl;
            count++;
         }
    }

cout<< " It occured "<<count<<" times \n";
}
int main()
{
    int N;
    int x;
    int *arr = new int[N];
    cout<<"Enter the size of the array and the element to be searched \n";
    cin >>N>>x;
    for(int i=0;i<N;i++)
    {
        cin>>arr[i];
    }
    search(arr,N,x);
    
    delete[] arr;       // To delete dynamically allocated memory for the array arr
    
    return 0;

}
