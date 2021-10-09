#include<stdio.h>

// recursive function 
int fact(int num)
{  if(num == 0)
    {
        return 1;
    }
   return num*fact(num-1);
}
// main function 
void main()
{ 
	int number =3 ;
	printf("Enter the number to find factorial \n");
	scanf("%d",&number);
	printf("%d ",number);
    
    printf("factorial is %d",fact(number))  ;  

    
}
