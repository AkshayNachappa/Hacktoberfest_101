#include<stdio.h>
#include<stdlib.h>
struct node
{
	int coef,pow;
	struct node* next;
};
struct node*h1=NULL;
struct node*h2=NULL;
struct node*h3=NULL;
struct node* getNode(int n,int e)
{
	struct node*nw=(struct node*)malloc(sizeof(struct node));
	if(nw==NULL)
	{
		printf("No memory allocated.");
		return NULL;
	}
	nw->coef=n;
	nw->pow=e;
	nw->next=NULL;
	return nw;
}
void insert(int n,int e,int i)
{
	struct node* p=NULL;
	if(i==1)
	{
		if(h1==NULL)
		{
			h1=getNode(n,e);
			return;
		}
		p=h1;
		while(p->next!=NULL)	
			p=p->next;
		p->next=getNode(n,e);
		return;
	}
	if(i==2)
	{
		if(h2==NULL)
		{
			h2=getNode(n,e);
			return;
		}
		p=h2;
		while(p->next!=NULL)	
			p=p->next;
		p->next=getNode(n,e);
		return;
	}
	if(i==3)
	{
		if(h3==NULL)
		{
			h3=getNode(n,e);
			return;
		}
		p=h3;
		while(p->next!=NULL)	
			p=p->next;
		p->next=getNode(n,e);
		return;
	}
}
void subpoly()
{
	struct node*p1=h1,*p2=h2,*p3=h3;
	while(p1!=NULL && p2!=NULL)
	{
		if(p1->pow>p2->pow)
		{
			insert(p1->coef,p1->pow,3);
			p1=p1->next;
		}
		else if(p1->pow==p2->pow)
		{
			insert(p1->coef-p2->coef,p1->pow,3);
			p1=p1->next;
			p2=p2->next;
		}
		else if(p1->pow<p2->pow)
		{
			insert(p2->coef,p2->pow,3);
			p2=p2->next;
		}
	}
	while(p2!=NULL)
	{
		insert(p2->coef,p2->pow,3);
		p2=p2->next;
	}
	while(p1!=NULL)
	{
		insert(p1->coef,p1->pow,3);
		p1=p1->next;
	}
}
void display(struct node *h)
{
	struct node*p;
	p=h;
	
	for(p=h;p->next!=NULL;p=p->next)
	{
		printf(" %dx^%d ",p->coef,p->pow);
		if(p->next!=NULL)
		   printf("+");
	}
	printf(" %dx^%d ",p->coef,p->pow);
}

void main()
{
	int n,e=0,i=1,t1,t2;
	printf("Enter number of terms in poly 1\n");
	scanf("%d",&t1);
	printf("Enter number of terms in poly 2\n");
	scanf("%d",&t2);
	for(i=1;i<=t1;i++)
	{
		printf("Enter the coefficient\n");
		scanf("%d",&n);
		printf("Enter the power of x for the coefficient entered.\n");
		scanf("%d",&e);
		insert(n,e,1);
	}
	display(h1);
	printf("\n");
	for(i=1;i<=t2;i++)
	{
		printf("Enter the coefficient\n");
		scanf("%d",&n);
		printf("Enter the power of x for the coefficient entered.\n");
		scanf("%d",&e);
		insert(n,e,2);
	}
	display(h2);
	printf("\n");
	subpoly();
	display(h3);
}
