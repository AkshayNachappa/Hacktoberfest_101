#include<stdio.h>
#include<math.h>
int main()
{
	int i,m=0,sum=0,n;
	printf("enter no.");
	scanf("%d",&n);
	m=n;
	while(m!=0)
	{
		int a=m%10;
		sum=sum+pow(a,3);
		m=m/10;
	}
	if(sum==n)
	printf("armstrong no.");
	else
	printf("not a armstrong no.");
}
