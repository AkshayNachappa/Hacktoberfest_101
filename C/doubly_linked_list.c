#include<stdio.h>
#include<conio.h>
struct node
{
 int info;
 struct node *lptr;
 struct node *rptr;
};
struct node FIRST;
void insertbeg()
{
 struct node *newnode;
 printf("Enter Value to Insert: ");
 scanf("%d",&newnode->info);
 newnode->lptr;
 if(FIRST==NULL)
 {
  newnode->rptr=NULL;
  FIRST=newnode;
 }
 else
 {
  newnode->rptr=FIRST;
  FIRST=newnode;
 }
 printf("Node Inserted.")
}
void insertend()
{
 struct node *newnode,*temp;
 printf("Enter Value to Insert: ");
 scanf("%d",&newnode->info);
 newnode->rptr=NULL;
 if(FIRST==NULL)
 {
   newnode->lptr=NULL;
   FIRST=newnode;
 }
 else
 {
  temp=FIRST;
  while(temp->rptr!=NULL)
     temp=temp->rptr;
  temp->rptr=newnode;
  newnode->lptr=temp;
 }
 printf("Node Inserted.s")
}
void deletebeg()
{
 if(FIRST==NULL)
  printf("List is Empty.")
 else if(FIRST->rptr==NULL)
 {
  printf("Deleted node: %d",FIRST->info);
  FIRST=NULL;
 }
 else
 {
  printf("Deleted node: %d",FIRST->info);
  FIRST=FIRST->rptr;
  FIRST->lptr=NULL
 }
}