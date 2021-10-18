#include <stdio.h>

void swap(int*x, int*y)

{

int temp;

temp=*x;
*x=*y;
*y=temp;

}

int main()

{

int a,b;

printf("\nEnter the Values of a & b\n");
scanf("%d %d", &a, &b);

printf("\nValues of a & b Before Swapping : \n a = %d \n b = %d \n", a, b);

swap(&a,&b);

printf("\nValues of a & b After Swapping : \n a = %d \n b = %d \n", a, b);

getch ();

return 0;

}
