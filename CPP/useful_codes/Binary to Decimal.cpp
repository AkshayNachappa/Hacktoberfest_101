#include<iostream>
#include<cmath>
using namespace std;
/*
This Code Convert the Binary Number to Decimal Number.
For Example:
   Input: 101
   Output: 5
*/
int BinarytoDecimal(long int n);
int main()
{
 long int num;
// cout<<"Enter a Binary Number: ";
  cin>>num;
 cout<<"Decimal Number of "<<num<<" : "<<BinarytoDecimal(num);
 return 0;
}
int BinarytoDecimal(long int n)
{
 int i=0,r,decNum=0;
 while(n>0)
 {
  r=n%10;
  decNum=decNum +  r * pow(2,i);
  i++;
  n=n/10;
 }
 return decNum;
}

