#include<stdio.h>
#include<conio.h>
int areas(int);
int area(int,int);
void main()
{
  int l,b,r;
  int(*S)(int);
  S=areas;
  printf("Enter Length of Square: ");
  scanf("%d",&r);
  printf("Area of Square: %d\n",(*S)(r));
  int(*R)(int ,int);
  R=area;
  printf("Enter length and Breath of Rectangle:");
  scanf("%d %d",&l,&b);
  printf("Area of Rectangle: %d",(*R)(l,b));
  getch();
}
int areas(int l)
{
  return(l*l);
}
int area(int l,int b)
{
  return(l*b);
}
