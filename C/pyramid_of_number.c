/*
Program to print half pyramid a using numbers

1
1 2
1 2 3
1 2 3 4
1 2 3 4 5

*/
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int i,k=1,j;
    for( i=1;i<=5;i++)
    {
        for(int j=1;j<=i;j++)
        {
            if(j<=i)
            printf("%d ",j);
        }
        printf("\n");

    }
    return 0;
}
