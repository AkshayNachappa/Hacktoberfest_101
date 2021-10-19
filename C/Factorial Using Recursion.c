#include <stdio.h>
#include <stdlib.h>

int factorial(int n) {
    if(n==0 || n==1) {
        return 1;
    } else {
        return factorial(n-1)*n;
    }
}

int main()
{
    int num;
    printf("Enter Number to find the factorial: ");
    scanf("%d",&num);
    printf("\n The factorial of %d is %d",num,factorial(num));;
    return 0;
}
