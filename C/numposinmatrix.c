// Enter 6 digit  and  find the psotion of Any digit in the matrix
#include<stdio.h>
int main()
{
    int arr[2][3],i,j,num,rowpos=0,colpos=0;
    printf("Enter 6 elements");
    for(i=0;i<2;i++)
    {
        for(j=0;j<3;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    printf("enter the num");
    scanf("%d",&num);
    for ( i = 0; i <2; i++)
    {
          for ( j = 0; j < 3; j++)
          {
              if(num==arr[i][j])
              {
                  rowpos=i+1;
                  colpos=j+1;
              }
          }
          
    }
   if (rowpos>0|| colpos>0)
   {
      printf("number found at\n row position=%d,\n column position = %d",rowpos, colpos);
   }
   else{
       printf("not");
   }
    return 0;
}
