#include<stdio.h>

void swap(int , int );

int main()
{
    int x,y;
    printf("Enter number x\n");
    scanf("%d",&x);
    printf("Enter number y\n");
    scanf("%d",&y);
    swap(x,y);
    return 0;
}

void swap ( int a, int b)
{
    a = a + b;
    b = a - b;
    a = a - b;
    printf("\nAfter swapping: x = %d and y = %d\n", a, b); 
}
