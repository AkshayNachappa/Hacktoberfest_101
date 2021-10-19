#include<stdio.h>
#include<math.h>
void push(int a[],int top,int item)
{
    a[top]=item;
}
int pop(int a[],int top)
{
    int item;
    item=a[top];
    return item;
}
void display(int a[],int top)
{
    int i;
    for(i=1;i<=top;i++)
    {
        printf("\n%d",a[i]);
    }
}
void main()
{
    int tops,item,topa,topd,max=20,s[20],a[20],d[20],n,i,l,x;
    topa=0; tops=0; topd=0;
    printf("Enter the number of rings : ");
    scanf("%d",&n);
    for(i=n; i>=1; i--)
    {
        if(tops==max)
            printf("No more space");
        else{
            tops++;
            s[tops]=i;
        }
    }
    tops=n;
    printf("\nSource ring : ");
    display(s,tops);
    x = pow(2, n)-1;
    i=1;
    if(n%2==0)
    {
        while(i<=x)
        {
            if(i%3==1)
            {
                if((s[tops]<a[topa])||(topa==0)){
                    item=pop(s,tops);
                    tops--;
                    topa++;
                    push(a,topa,item);
                    printf("\nTransferred from source to auxiliary ");
                }
                else{
                    item=pop(a,topa);
                    topa--;
                    tops++;
                    push(s,tops,item);
                    printf("\nTransferred from auxiliary to source ");
                }
            }
            else if(i%3==2)
            {
                if((s[tops]<d[topd])||(topd==0)){
                    item=pop(s,tops);
                    tops--;
                    topd++;
                    push(d,topd,item);
                    printf("\nTransferred from source to destination ");
                }
                else{
                    item=pop(d,topd);
                    topd--;
                    tops++;
                    push(s,tops,item);
                    printf("\nTransferred from destination to source ");
                }
            }
            else if(i%3==0)
            {
                if((d[topd]<a[topa])||(topa==0)){
                    item=pop(d,topd);
                    topd--;
                    topa++;
                    push(a,topa,item);
                    printf("\nTransferred from destination to auxiliary ");
                }
                else{
                    item=pop(a,topa);
                    topa--;
                    topd++;
                    push(d,topd,item);
                    printf("\nTransferred from auxiliary to destination ");
                }
            }
            i++;
        }

    }
    else
    {
        while(i<=x)
        {
            if(i%3==1)
            {
                if((s[tops]<d[topd])||(topd==0)){
                    item=pop(s,tops);
                    tops--;
                    topd++;
                    push(d,topd,item);
                    printf("\nTransferred from source to destination ");
                }
                else{
                    item=pop(d,topd);
                    topd--;
                    tops++;
                    push(s,tops,item);
                    printf("\nTransferred from destination to source ");
                }
            }
            else if(i%3==2)
            {
                if((s[tops]<a[topa])||(topa==0)){
                    item=pop(s,tops);
                    tops--;
                    topa++;
                    push(a,topa,item);
                    printf("\nTransferred from source to auxiliary ");
                }
                else{
                    item=pop(a,topa);
                    topa--;
                    tops++;
                    push(s,tops,item);
                    printf("\nTransferred from auxiliary to source ");
                }
            }
            else if(i%3==0)
            {
                if((a[topa]<d[topd])||(topd==0)){
                    item=pop(a,topa);
                    topa--;
                    topd++;
                    push(d,topd,item);
                    printf("\nTransferred from auxiliary to destination ");
                }
                else{
                    item=pop(d,topd);
                    topd--;
                    topa++;
                    push(a,topa,item);
                    printf("\nTransferred from destination to auxiliary ");
                }
            }
            i++;
        }
    }
    printf("\nDestination ring : ");
    display(d,topd);
}
