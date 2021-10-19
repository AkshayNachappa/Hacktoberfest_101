#include <iostream> 
using namespace std; 

int fib(int n)  {
    if(n==0 || n==1) {
        return n;
    }

    return fib(n-1) + fib(n-2); 
}

int main() {
    int n;
    cout<<"Enter the term";
    cin>>n;

    cout<<"The nth term is "  <<fib(n+1);
    

    return 0;
}