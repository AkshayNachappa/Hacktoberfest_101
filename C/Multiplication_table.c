#include<stdio.h>
int main()
{
	int i;
	int j;
	int c;
	printf("Enter the number\n");
	scanf("%d",&j);
	printf("Multiplication table for %d is:\n",j);
	for(i=0; i<=10; i++)
	{
	  c=i*j;
	  printf("%d*%d=%d \n",i,j,c);
	}
	
    return 0;
}