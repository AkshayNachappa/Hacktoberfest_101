#include <iostream>
#include <cmath>
using namespace std;
/*
 In this Program:
--> Enter a Number with No Space and No Commas.
--> Supports Upto 11 Digits Number Now.
For Example:


 Input: 193
 Output: one hundred ninety three

 Input: 1996
 Output: one thousand nine hundred ninety six

*/
 string sidigit[]={"Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};

 string twodigit[]={"Ten","Eleven","Twelve","Thirth","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Ninteen"};

 string tenmul[]={"","","Twenty","Thirty","Fourty","Fifty","Sixty","Seventy","Eighty","Ninty"};

 string tenpow[]={"Hundred","Thousand","Million","Billion","Trillion"};

string tenpow_ind[]={"Hundred","Thousand","Lakh","Crore","Arab"};

string Words_ConvertInt(long int number)
{
 string str;
 long int digit=0,n=number;
  while(n!=0){
    digit++;
    n=n/10;
  }

 long int m;
 if(digit==1) m=10;
 else m=pow(10,digit-1);

 long int q,r;
 q=number/m;
 r=number%m;

 long int x;

 switch(digit)
 {
  case 1:
         str=str+sidigit[r];
         break;
  case 2:
         if(q==1){
          str=str+twodigit[r];
          return str;
         }
         else
          str=str+tenmul[q];
         break;
  case 3:
         str=str+sidigit[q];
         str=str+" "+tenpow[0];
         break;
  case 4:
         str=str+" "+sidigit[q];
         str=str+" "+tenpow[1];
         break;
  case 5:
         if(q==1)
          str=str+" "+twodigit[r/1000];
         else{
           str=str+tenmul[q];
           if(r)
            str=str+" "+sidigit[r/1000];
           }
           r=r%1000;
           str=str+" "+tenpow[1];
         break;
  case 6:
         str=str+sidigit[q];
         str=str+" "+tenpow[0];
          q=r/10000;
          r=r%10000;
         if(q==1)
            str=str+" "+twodigit[r/1000];
         else{
            str=str+" "+tenmul[q];
            str=str+" "+sidigit[r/1000];
          }
           r=r%1000;
           str=str+" "+tenpow[1];
         break;
  case 7:
         str=str+" "+sidigit[q];
         str=str+" "+tenpow[2];
         break;
  case 8:
         x=r/1000000;
         if(q==1)
          str=str+" "+twodigit[x];
         else{
          str=str+" "+tenmul[q];
          str=str+" "+sidigit[x];
         }
          r=r%1000000;
         str=str+" "+tenpow[2];
         break;
  case 9:
         str=str+" "+sidigit[q];
         str=str+" "+tenpow[0];
          x=r/10000000;
          r=r%10000000;
         if(x==1)
          str=str+" "+twodigit[r/1000000];
         else{
          str=str+" "+tenmul[x];
          str=str+" "+sidigit[r/1000000];
         }
         str=str+" "+tenpow[2];
         r=r%1000000;
         break;
 case 10:
         str=str+sidigit[q];
         str=str+" "+tenpow[3];
         break;
 case 11:
         x=r/1000000000;
         if(q==1)
          str=str+" "+twodigit[x];
         else{
          str=str+" "+tenmul[q];
          str=str+" "+sidigit[x];
         }
          r=r%1000000000;
         str=str+" "+tenpow[3];
         break;

 }

 if(r && digit!=1)
   str=str+" "+Words_ConvertInt(r);

 return str;
}

/* For Indian Number System */
string Words_ConvertInd(long int number)
{
 string str;
 long int digit=0,n=number;
  while(n!=0){
    digit++;
    n=n/10;
  }

 long int m;
 if(digit==1) m=10;
 else m=pow(10,digit-1);

 long int q,r;
 q=number/m;
 r=number%m;

 long int x;

 switch(digit)
 {
  case 1:
         str=str+sidigit[r];
         break;
  case 2:
         if(q==1){
          str=str+twodigit[r];
          return str;
         }
         else
          str=str+tenmul[q];
         break;
  case 3:
         str=str+sidigit[q];
         str=str+" "+tenpow_ind[0];
         break;
  case 4:
         str=str+" "+sidigit[q];
         str=str+" "+tenpow_ind[1];
         break;
  case 5:
         x=r/1000;
         if(q==1)
          str=str+" "+twodigit[x];
         else{
           str=str+tenmul[q];
           if(r)
            str=str+" "+sidigit[x];
           }
           r=r%1000;
           str=str+" "+tenpow_ind[1];
         break;
 //Different
  case 6:
         str=str+" "+sidigit[q];
         str=str+" "+tenpow_ind[2];
         break;
  case 7:
         x=r/100000;
         if(q==1)
          str=str+" "+twodigit[x];
         else{
           str=str+tenmul[q];
           if(r)
            str=str+" "+sidigit[x];
          }
          r=r%100000;
          str=str+" "+tenpow_ind[2];
         break;
  case 8:
         str=str+" "+sidigit[q];
         str=str+" "+tenpow_ind[3];
         break;
  case 9:
         x=r/10000000;
         if(q==1)
          str=str+" "+twodigit[x];
         else{
           str=str+tenmul[q];
           if(r)
            str=str+" "+sidigit[x];
          }
          r=r%10000000;
          str=str+" "+tenpow_ind[3];
         break;
 case 10:
         str=str+" "+sidigit[q];
         str=str+" "+tenpow_ind[4];
         break;
 case 11:
         x=r/1000000000;
         if(q==1)
          str=str+" "+twodigit[x];
         else{
           str=str+tenmul[q];
           if(r)
            str=str+" "+sidigit[x];
          }
          r=r%1000000000;
          str=str+" "+tenpow_ind[4];
         break;
 }

 if(r && digit!=1)
   str=str+" "+Words_ConvertInd(r);

 return str;
}

int main()
{
 long int number;
// cout<<"Enter a Number: ";
 cin>>number;
 cout<<"Entered Number: "<<number<<endl<<endl;

 cout<<"In 🌐 International Number System :\n\n--> "<<Words_ConvertInt(number)<<endl<<endl<<endl;

 cout<<"In 🇮🇳 Indian Number System :\n\n--> "<<Words_ConvertInd(number);

  cout<<"\n\n\n1  Million = 10 Lakhs"<<endl;
  cout<<"10 Million = 1 Crore"<<endl;
  cout<<"100 Million = 10 Crores"<<endl;
  cout<<"1  billion  = 100 Crores"<<endl;
  cout<<"10  billion  = 1000 Crores"<<endl;


 return 0;
}

