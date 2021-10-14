#include <iostream>
using namespace std;
/*
 This Code Convert Decimal Number into Binary Number.
 For Example:
 Input: 10
 Output:1010
*/
void DecimaltoBinary(int);
int main()
{
 int num,n;
 cin>>num;

 cout<<"Binary Converstion of "<<num<<" : ";
 n=num;
 if(num<=0){
  if(num==0)
   cout<<"00000000";
  else
   cout<<"Enter Positive Number: ";
 }
 else
  DecimaltoBinary(n);
 return 0;
}
void DecimaltoBinary(int n)
{
 int rem;
 if(n==0)
  return;
 else{
  rem=n%2;
  DecimaltoBinary(n/2);
  cout<<rem;
  }
}
