

#include <iostream>
using namespace std;

void pascal_pattern(int n)
{
   
  for(int row=1;row<=n;row++)
  {
    for(int s=1;s<=n-row;s++)
    {
        cout<<"  ";
    }
    
    int numerator=row-1,denominator=1,num=1;
    
   for(int col=1;col<=row;col++)
   {
    cout<<num<<"   ";
    //num=(num*numerator)/denominator;
    num=num*numerator;
    num=num/denominator;
    numerator--;
    denominator++;
   }
   cout<<endl;
  }
}

int main()
{
    int n;
   cout<<"enter value of n:"<<endl;
   cin>>n;
  
pascal_pattern(n);
  
    return 0;
}

