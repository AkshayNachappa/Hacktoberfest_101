# include <stdio.h>
# include <string.h>

int main()
{

char delete[]="the sun rises in east and sets in the west the the the the the ";;

int i;

for(i=0;delete[i]!=0;i++)
{
if(delete[i]==116&&delete[i+1]==104&&delete[i+2]==101&&delete[i+3]==32)
{
for(;delete[i+4]!=0;i++)
delete[i]=delete[i+4];

delete[i]='\0';
i=-1;
}
}

printf("\n%s",delete);
return 0;
}
