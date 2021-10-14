#include<stdio.h>
#include<conio.h>
void main()
{
 int moncode[14]={0,1,4,4,0,2,5,0,3,6,1,4,6};
 int date,month,year;
 int c=0,cen,yr,ly,Result;
  printf("Enter your Date in Format DD-MM-YYYY:\n");
   scanf("%d %d %d",&date,&month,&year);
  cen=year/100;
       if(cen==0||cen==4||cen==8||cen==12 ||cen==16||cen==20||cen==24||cen==28||cen==32||cen==36||cen==40||cen==44||cen==48)
         c=6;
  else if(cen==1||cen==5||cen==9||cen==13 ||cen==17||cen==21||cen==25||cen==29||cen==33||cen==37||cen==41||cen==45||cen==49)
       c=4;
  else if(cen==2||cen==6||cen==10||cen==14 ||cen==18||cen==22||cen==26||cen==30||cen==34||cen==38||cen==42||cen==46||cen==50)
       c=2;
  else if(cen==3||cen==7|| cen==11 ||cen==15||cen==19||cen==23||cen==27||cen==31||cen==35||cen==39||cen==43||cen==47||cen==51)
       c=0;
  yr=year%100;
  ly=yr/4;
  Result=date+moncode[month]+c+yr+ly;
  if(yr%4==0)
  {
   if(month==1 || month==2)
      Result=Result-1;
  }
  printf("The DATE %d-%d-%d And DAY is: ",date,month,year);
  switch(Result%7)
  {
    case 0:printf("SATURDAY.\n");
           break;
    case 1:printf("SUNDAY.\n");
           break;
    case 2:printf("MONDAY.\n");
           break;
    case 3:printf("TUESDAY.\n");
           break;
    case 4:printf("WEDNESDAY.\n");
           break;
    case 5:printf("THURSDAY.\n");
           break;
    case 6:printf("FRIDAY.\n");
           break;
  }
  getch();
}
