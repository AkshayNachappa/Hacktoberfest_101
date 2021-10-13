#include<stdlib.h>
#include<stdio.h>
// using namespace std;
struct node{
    float coeff;
    int expo;
    struct node * link;   
};


struct  node* insert(struct node* head,float co,int ex)
{
struct node* temp;
struct node*newP=malloc(sizeof(struct node));
newP->coeff =co;
newP->expo=ex;
newP->link=NULL;
if(head==NULL || ex>head->expo)
{  newP->link=head;
 head=newP;
} 
else{
    temp=head;
    while (temp->link!=NULL && temp->link->expo>=ex)
    {
        temp=temp->link;
    }
    newP->link=temp->link;
    temp->link=newP;

}
return head;
}
void print(struct node* head)
{
    if(head==NULL)
    {
        printf("empty list");
    }
    else{
        struct node* temp=head;
        while (temp!=NULL)
        {
            printf("(%.1fx^%d)",temp->coeff,(int) temp->expo);
            temp=temp->link;
            if(temp!=NULL)
            {
                printf("+");
            }
            else
            {
                printf("\n");
            }
        }
        
    }
}
void polyMult(struct node* head1,struct node* head2)
{
  struct node* ptr1=head1;
  struct node* ptr2=head2;
  struct node* head3=NULL;
  //check if first or second polynomial is null
  if(head1==NULL || head2==NULL )
  {
      printf("Zero Polynomial");
      return;
  }
  //Multiplication of two polynomial
  while(ptr1!=NULL)
  {
      while(ptr2!=NULL){
          head3=insert(head3,ptr1->coeff * ptr2->coeff,ptr1->expo + ptr2->expo);
          ptr2=ptr2->link;
      }
      ptr1=ptr1->link;
      ptr2=head2;
  }
  print(head3);
 }
struct node* create(struct node* head)
{
    int n,i;
    float coeff;
    int expo;
    printf("enter the num of terms: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("enter the coeff for %d:",i+1);
        scanf("%f",&coeff);

        printf("enter the expo for %d:",i+1);
        scanf("%d",&expo);
        
        head=insert(head,coeff,expo);
    }
    return head;
}

int main()
{
    struct node* head1=NULL;
    struct node* head2=NULL;
   printf("enter the first polynomial\n");
   head1=create(head1);

 printf("enter the second polynomial\n");
   head2=create(head2);

   polyMult(head1,head2);
   return 0;
}