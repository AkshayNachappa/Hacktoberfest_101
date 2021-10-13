#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
 int info;
 struct node *left;
 struct node *right;
};
struct node *ROOT;
void preorder(struct node *root)
{
 if(root==NULL)
    printf("Tree is Empty.");
 printf("%d",root->info);
 if(root->left!=NULL)
    preorder(root->left);
 if(root->right!=NULL)
    preorder(root->right);
}
void insertnode()
{
 struct node *newnode;
 int data;
 printf("Enter Value: ");
 scanf("%d",&data);
 newnode=(struct node*)malloc(sizeof(struct node));
 newnode->info=data;
 newnode->left=NULL;
 newnode->right=NULL;
 if(ROOT=NULL)
 {
  ROOT=newnode;
  printf("Node Inserted.");
 }
 else
 {
  while(ROOT!=NULL)
   {
    if(ROOT->info>data)
     {
       ROOT->left=newnode;
      ROOT=ROOT->left;
     }
   else if(ROOT->info<data)
     {
       ROOT->right=newnode;
      ROOT=ROOT->right;
     }
   }
 }
}
int main()
{
 int ch;
 while(1)
 {
 printf("1 INSERTION.\n");
 printf("2 PRE-ORDER TRAVERSAL.\n");
 printf("3 Exit.\n");
 printf("Enter your Choice: ");
 scanf("%d",&ch);
  switch(ch)
  {
   case 1:insertnode();
         break;
   case 2:preorder(ROOT);
         break;
   case 3:exit(0);
  }
 }
}
