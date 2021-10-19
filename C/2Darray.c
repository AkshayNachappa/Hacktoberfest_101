#include <stdio.h>
int main()
{ int i,j;
   int marks[4][6]={{13, 14, 15, 16, 17, 18},{1, 2, 3, 4, 5, 6},{20, 21, 22, 23, 24, 25},{7, 8, 9, 10, 11, 12}};
   for(i=0;i<4;i++)
   {
       for (j = 0; j < 6; j++)
           printf("%d ",marks[i][j]);
   printf("\n");
   }
    return 0;
}
