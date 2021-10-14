#include <iostream>
using namespace std;
/*
In all programming languages, there are some naming conventions for variables.

Some conventions are the following:
1. A valid variable name can contain only alphabetic characters (a-z, A-Z), digits (0-9) and underscores(_).
2. It can't contain any special character (@, #, %, &, *, etc...) or any white space.
3. A valid variable name never starts with any digit.
4. A variable name can't be a keyword(depends on the language you are using).

Create a program that takes a variable name as input and outputs whether it is valid or not.

For example:
Input: num1
Output: Valid

Input: num_1
Output: Valid

Input: 1num
Output: Invalid

Input: if
Output: Invalid

*/
int main()
{
 char s[20];
 int i,flag=0;
            // cout<<"Enter a Variable name:";
 cin>>s;
 cout<<"Your Variable Name: "<<s<<endl;
 if((s[0]>=33 && s[0]<=57) || (s[0]>=91 && s[0]<=94))
  cout<<"INVALID NAME.";
 else
 {
  for(i=0;s[i]!='\0';i++)
  {
  if((s[i]>=33 && s[i]<=47) || (s[0]>=91 && s[0]<=94))
   {
     flag=1;
     break;
   }
  }
  if(flag==1)
   cout<<"INVALID NAME.";
  else
   cout<<"VALID NAME.";
 }
 return 0;
}
