#include<stdio.h>
int main()
{
    int a,b,i,n,result,res=0;
    printf("Enter the numbers till which you want to find the fibonacci series:");
    scanf("%d",&n);

    a=0;
    b=1;
    
    for(i=1;i<=n;i++)
    {
        printf(" %d ",a);
        result=a+b;
        a=b;
        b=result;
    }
    res=a+res;
    
}

