#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* link;
};

struct node* tos;

int isEmpty() {
    return tos== NULL? 1 : 0;
}

void push() {
    int x;
    printf("\n Enter the data to enter.");
    scanf("%d",&x);

    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->link = NULL;

    newnode->link = tos;
    tos = newnode;
}

void pop() {
    struct node* temp = tos;
    if( isEmpty() ) {
        printf("\n Stackis Empty. Enter elements first.");
        return;
    }   printf("\n Element poped %d",tos->data);
        tos=tos->link;
        free(temp);
}

int main()
{
    tos = NULL;
    int choice;
    while(1) {
        printf("\n Press 1 for push operation.");
        printf("\n Press 2 for pop operation.");
        printf("\n Press 3 for Checking Empty or not.");
        printf("\n Enter your choice: ");
        scanf("%d",&choice);

        switch(choice) {
        case 1:
            push();
            break;

        case 2:
            pop();
            break;

        case 3:
            isEmpty()? printf("\n Stack is Empty") : printf("\n Stack is not Empty");
            break;

        case 4:
            return 0;
        }
    }

    return 0;
}
