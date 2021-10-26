#include<iostream>
using namespace std;

int main()
{
    int i,n, first=0, second=1, next;

    first=0;
    second=1;

    cout<<"How many terms u want to Display :: ";
    cin>>n;

    cout<<"\nThe Fibonacci series for [ "<<n<<" ] terms are :: \n\n";
    for(i=0; i<n; i++)
    {
        cout<<" "<<first<<" ";
        next = first + second;
        first = second;
        second = next;
    }

    cout<<"\n";

    return 0;
}