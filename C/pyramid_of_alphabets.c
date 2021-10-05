/*
Program to print half pyramid using alphabets
A
B B
C C C
D D D D
E E E E E
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    int i,k=1,j;
    for( i=65;i<70;i++)
    {
        for(j=65;j<=i;j++)
        {
            if(j<=i)
            printf("%c ",i);
        }
        printf("\n");
    }
    return 0;
}
