#include<stdio.h>
int main(void)
{
char name[10];
char appoinment_type;
int patient_num;
int i;

printf("Appoinment Method		Type\n");
printf("    Consulting		        C\n"); 
printf("    Scanning			S\n"); 
printf("    Testing			T\n\n");        

FILE *cPfrt;
cPfrt=fopen("appoinment.dat","w");

	if (cPfrt==NULL)
	{
		printf("Cannot open this file");
	}

for(patient_num=1;patient_num<=5;patient_num=patient_num+1)
	{
	printf("Enter your name: ");
	scanf("%s",name);
	printf("Enter your Appoinment type: ");
	scanf(" %c", &appoinment_type);	
		i=1;
		while(i==1)
		{
			if (appoinment_type == 'C' || appoinment_type == 'c')
        		{
				i = 0;
        		}
        		else 
			{
				if (appoinment_type == 'S' || appoinment_type == 's')
        			{
					i = 0;
       	 			}	
        			else
				{
					if (appoinment_type == 'T' || appoinment_type =='t')
        				{
						i = 0;
        				}
					else
					{
						printf("Not available appoinment type\n");
						printf("Enter your name: ");
						scanf(" %s",name);
						printf("Enter your Appoinment type : ");
       						scanf(" %s", &appoinment_type); 
					}
				}
			}
		}	
		fprintf(cPfrt,"%s          %c\n",name ,appoinment_type);
	}
fclose(cPfrt);
return 0;
}