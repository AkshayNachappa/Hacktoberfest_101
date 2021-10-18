#include<conio.h>
#include<stdlib.h>
#include<math.h>
#include<stdio.h>
#include<graphics.h>
void main()
{
int gdriver=DETECT,gmode,error,x1,y1,x2,y2;
int dx,dy,x,y,p;
initgraph(&gdriver,&gmode, "C:\\TURBOC3\\BGI");
printf(" please enter 1st point ");
scanf("%d%d",&x1,&y1);
printf(" please enter 2nd point ");
scanf("%d%d",&x2,&y2);
cleardevice();
outtextxy(200,4,"Draw using BRESHNAM'S  by Piyush @@");
dx=x2-x1;
dy=y2-y1;
x=x1;
y=y1;
p=2*dy-dx;
while(x<x2)
{
if(p>=0)
{
putpixel(x,y,7);
y=y+1;
p=p+2*dy-2*dx;
}
else
{
putpixel(x,y,7);
delay(45);
p=p+2*dy;
}
x=x+1;
}
getch();
}
