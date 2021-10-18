/*
-> Roman Numerals are a system of numerical notations used by the Romans.

-> Romans Numerals are based on the following symbols:
   I = 1
   V = 5
   X = 10
   L = 50
   C = 100
   D = 500
   M = 1000

(IV) = 4000
(V)  = 5000
(X)  = 10,000
(L)  = 50,000
(C)  = 1,00,000
(D)  = 5,00,000
(M)  = 10,00,000

NOTE: Above Notations.
      (n) -> means n bar
          -> Where Bar is 1000 time of Given Number.
          -> So,n=n*1000;
*/

#include <iostream>
#include <cmath>
using namespace std;

string roman[]={"I","V","X","L","C","D","M",""};

string Roman_Convert(int num)
{
 int r,q;
 string str;

 int d=0,n=num,v=0;
  while(n!=0){
   d++;
   n=n/10;
   if(d>1)
    v=v+2;
  }

 int m;
 if(d==1) m=10;
 else m=pow(10,d-1);

 q=num/m;
 r=num%m;

 int x;
 if(d==1) x=r;
 else  x=q;

 int i=0;
 if(x<=3)
 {
   while(++i<=x)
    str=str+roman[v];
 }
 else if(x==4)
   str=roman[v]+roman[v+1];
 else if(x>=5 && x<=8)
 {
   str=roman[v+1];
   i=0;
   while(++i<=x-5)
    str=str+roman[v];
 }
 else if(x==9){
   str=roman[v]+roman[v+2];
 }

 if(r && d!=1)
  str=str+ Roman_Convert(r);

 return str;
}


int main()
{

 int num;
 string str;
//cout<<"Enter a Number : ";
 cin>>num;
 cout<<"Entered Number : "<<num<<endl<<endl;

 if(num<0){
    cout<<"No Roman Letter for 0(zero).";
    exit(0);
  }
 else if(num<4000)
   str=Roman_Convert(num);
 else if(num>3999)
 {
   str="("+Roman_Convert(num/1000)+")";
   if(num%1000)
    str=str+ Roman_Convert(num%1000);
 }

 cout<<"Roman Number : "<<str;
 return 0;
}


