/*
This program will take a series of numbers and then produce a statistical report based on the given data. The report should include the Mean, Mode and Median. Also Draw the histogram for the given data.

For example:

Input: {2, 5, 2, 3, 4, 5, 1, 5, 3, 3, 4}

Output:

Mean: 3.36
Mode: 3, 5
Median: 3
Histogram:
1   |  *
2   |  **
3   |  ***
4   |  **
5   |  ***

*/

#include <iostream>
#include <iomanip>
using namespace std;

void Mean(int [],int);
void Median(int [],int);
void Mode(int [],int);

int main()
{
 int a[50]={2, 5, 2, 3, 4, 5, 1, 5, 3, 3, 4};
 int n=11,i;
// cout<<"Enter a Number of Values: ";
//    cin>>n;
// cout<<"Enter "<<n<<" Values: ";
//  for(i=0;i<n;i++)
//   cin>>a[i];
  cout<<"Entered Values : "<<endl;
  for(i=0;i<n;i++)
   cout<<a[i]<<" ";

  Mean(a,n);
  Median(a,n);
  Mode(a,n);

return 0;
}

void Mean(int a[],int n)
{
 int i,sum=0;
 float mean;
 for(i=0;i<n;i++)
  sum=sum+a[i];
 mean=(float)sum/n;
 cout<<"\n\nMean: "<<setprecision(3)<<mean<<endl;
}

void Median(int a[],int n)
{
 int i,j,median,temp;
 for(i=1;i<n;i++)
 {
  for(j=0;j<n-i;j++)
  {
   if(a[j]>a[j+1])
   {
    temp=a[j];
    a[j]=a[j+1];
    a[j+1]=temp;
   }
  }
 }
 median=a[n/2];
 cout<<"Median: "<<median<<endl;
}

void Mode(int a[],int n)
{
 int i,flag;
 int count[50],c,au[50],u=0,z;

 //Finding Unique Values
 for(i=0;i<n;i++)
 {
  flag=1;
  for(z=0;z<u;z++)
   if(au[z]==a[i])
    {
     flag=0;
     break;
    }
  if(flag)
   au[u++]=a[i];
 }

 //Occurenece of Values
 int f;
 for(f=0;f<u;f++)
 {
  c=0;
  for(i=0;i<n;i++)
   if(a[i]==au[f])
    c++;

  count[f]=c;
 }

 //Finding Mode
 int max=count[0] ;
 int md[50],m=0;

 for(z=1;z<u;z++){
  if(count[z]>max)
    max=count[z];
  }
  md[0]=max;
  for(z=0;z<u;z++){
   if(count[z]==max)
    md[m++]=au[z];
  }

 cout<<"Mode: ";
 for(i=0;i<m;i++)
  cout<<md[i]<<",";

 //Draw Histogram:
 cout<<"\nHistogram :"<<endl<<endl;
  for(i=0;i<u;i++)
  {
   cout<<setw(3)<<au[i]<<" | ";
    for(z=0;z<count[i];z++)
      cout<<"* ";
   cout<<endl;
  }
}
