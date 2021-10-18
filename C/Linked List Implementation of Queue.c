#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* link;
};

struct node* front;
struct node* rear;

int isEmpty() {
    return front== NULL && rear == NULL ? 1 : 0;
}

void enqueue() {
    int x;
    printf("\n Enter the data to enter.");
    scanf("%d",&x);

    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->link = NULL;

    if( isEmpty() ) {
        front = rear = newnode;
    } else {
        rear->link = newnode;
        rear = newnode;
    }
}

void dequeue() {
    struct node* temp = front;
    if( front ==NULL) {
        printf("\n Queue is Empty. Enter elements first.");
        return;
    } else if( front==rear ) {
        printf("\n Element deueued %d",front->data);
        front = rear = NULL;
    }
    else {
        printf("\n Element deueued %d",front->data);
        front=front->link;
    }
    free(temp);
}

int main()
{
    front = rear = NULL;
    int choice;
    while(1) {
        printf("\n Press 1 for Enqueue.");
        printf("\n Press 2 for Dequeue.");
        printf("\n Press 3 for Checking Empty or not.");
        printf("\n Enter your choice: ");
        scanf("%d",&choice);

        switch(choice) {
        case 1:
            enqueue();
            break;

        case 2:
            dequeue();
            break;

        case 3:
            isEmpty()? printf("\n Queue is Empty") : printf("\n Queue is not Empty");
            break;

        case 4:
            return 0;
        }
    }

    return 0;
}
