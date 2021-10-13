#include<stdio.h>
#include<conio.h>

int main()
{
 int a[10][10],i,j,R,C,sum,total;
 int r1,r2,r3,c1,c2,c3,d1,d2;
 R=3;C=3;
 printf("Enter Number of Rows and Columns: ");
 scanf("%d %d",&R,&C);
 total=R*C;
 printf("Enter %d Elements: ",total);
 for(i=0;i<R;i++){
  for(j=0;j<C;j++){
   scanf("%d",&a[i][j]);
  }
 }
 r1=a[0][0]+a[0][1]+a[0][2];
 r2=a[1][0]+a[1][1]+a[1][2];
 r3=a[2][0]+a[2][1]+a[2][2];
 c1=a[0][0]+a[1][0]+a[2][0];
 c2=a[0][1]+a[1][1]+a[2][1];
 c3=a[0][2]+a[1][2]+a[2][2];
 d1=a[0][0]+a[1][1]+a[2][2];
 d2=a[0][2]+a[1][1]+a[2][0];
 sum=r1;
 if(r1==r2 && r2==r3 && r3==c1 && c1==c2 && c2==c3 && c3==d1 && d1==d2 )
   printf("It is Magic Matrix. Sum is: %d",sum);
 else
   printf("It is Not Magic Matrix");
}
