/*
Enter a IP Addres as an input,This program Check Whether the Given   IP Addres is Valid IPv4 address or Not.

A valid IP address should be in the form of:
 a.b.c.d
 where a, b, c and d are integer values ranging from 0 to 255 inclusive.

For example:
127.0.0.1 - valid
127.255.255.255 - valid
257.0.0.1 - invalid
255a.0.0.1 - invalid
127.0.0.0.1 - invalid

*/
#include <iostream>
#include <cstring>
using namespace std;

int Number_Check(char *str)
{
 int i,num,n=0,arr[5],num_valid=1;

 for(i=0;str[i]!='\0';i++)
 {
  num=0;
   while(str[i]!='.' && str[i]!='\0'){
     num=num*10+str[i]-'0';
      i++;
   }
   if(num>=0 && num<=255)
     arr[n++]=1;
   else
     arr[n++]=0;
 }

 for(i=0;i<=3;i++)
   num_valid=num_valid && arr[i];

 return num_valid;
}

int Length_Check(char *str)
{
 int len=strlen(str);
 if(len>=7 && len<=15)
  return 1;
 else
  return 0;
}

int Dots_Check(char *str)
{
 int i,dot_valid=0;
  for(i=0;str[i]!='\0';i++)
  {
    if(str[i]=='.')
      dot_valid++;
  }
  if(dot_valid==3)
   return 1;
  else
   return 0;
}
int String_Check(char *str)
{
 int i,str_valid=1;
 for(i=0;str[i]!='\0';i++)
 {
  if((str[i]>=48 && str[i]<=57) || str[i]=='.')
    str_valid = str_valid && 1;
  else
    str_valid = str_valid && 0;
 }
 return str_valid;
}
int Check_IP(char *str)
{
 int str_valid= String_Check(str);
 int dot_valid= Dots_Check(str);
 int len_valid= Length_Check(str);
 int num_valid= Number_Check(str);
/*
 cout<<"Length : "<<len_valid<<endl;
 cout<<"Number : "<<num_valid<<endl;
 cout<<"Dots : "<<dot_valid<<endl;
 cout<<"String : "<<str_valid<<endl<<endl;
*/
 if(!len_valid)
   cout<<"\n-> Length of the IPv4 address is from 7 to 15   Characters.";
 if(!dot_valid)
   cout<<"\n-> IPv4 address can contain only 3 Dots.";
 if(!str_valid)
   cout<<"\n-> IPv4 address can contain only Digits and Dots.";
 if(!num_valid)
    cout<<"\n-> IPv4 address in Form of a.b.c.d \n\t\twhere a, b, c and d are integer values ranging from 0 to 255 inclusive.";

 if(len_valid && dot_valid && str_valid  && num_valid)
  return 1;
 else
  return 0;
}

int main()
{
 char address[20];
// cout<<"Enter a IP Address : ";
 cin.getline(address,20);
 cout<<"Entered IP Address : "<<address<<endl<<endl;

 if(Check_IP(address))
  cout<<"\n\n👍 Valid IP Address.";
 else
  cout<<"\n\n❌ Invalid IP Address.";
 return 0;
}
