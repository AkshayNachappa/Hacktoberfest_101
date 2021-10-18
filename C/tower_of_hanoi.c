#include<stdio.h>

void tower(int num, char frompeg, char topeg, char auxpeg)
{
    if(num==1)
    {
        printf("Move disk 1 from peg %c to pec %c", frompeg, topeg);
        return;
    }
    tower(num-1,frompeg,auxpeg,topeg);
    printf("\nMove disk %d from peg %c to pec %c\n",num,frompeg,topeg);
    tower(num-1,auxpeg,topeg,frompeg);
}

int main()
{
    int num;
    printf("Enter the number of disk: ");
        scanf("%d",&num);
    tower(num, 'A', 'C', 'B');
    return 0;
}
