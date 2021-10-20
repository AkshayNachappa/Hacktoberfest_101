/*C program to count all the occurrences of a particular word.*/

#include<stdio.h>
#include<string.h>
int main()
{
char str1[100], str2[100];
int i,j,l1,l2;
int count;
int no=0;
printf("Enter the string:\n");
gets(str1);
l1=strlen(str1);
printf("\nEnter the word:\n");
gets(str2);
l2=strlen(str2);
for (i=0;i<l1;i++)
{
j=0;
count=0;
while(str1[i]==str2[j])
{
i++;
j++;
count++;
}
if(count==l2)
{
no++;
}
}
printf("\nCount of occurence of the word %s = %i\n",str2,no);
}
