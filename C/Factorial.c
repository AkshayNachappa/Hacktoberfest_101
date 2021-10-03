#include<stdio.h>
void main()
{
	int i;
	int n;
	long factorial;
	factorial=1;
	printf("enter number to find its factorial \n");
	scanf("%d",&n);
	for(i=n;i>1;i--)
	{
		factorial*=i;
	}
	printf("factorial of %d is %d",n,factorial);
}
