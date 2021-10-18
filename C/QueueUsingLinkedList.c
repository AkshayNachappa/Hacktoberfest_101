/***This program is about Queue using Linked List****/
/***C-DSA***/
/***@Author : Soumyadip Ghosh (GitHub: https://github.com/SoumyadipGhosh23)***/

#include <stdio.h>
#include <stdlib.h>

struct node *f = NULL;
struct node *r = NULL;
struct node
{
    int data;
    struct node *next;
};

void linkedListTraversal(struct node *ptr)
{
    printf("Printing the elements: \n");
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

void enqueue(int val)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    if (n == NULL)
    {
        printf("Queue is full\n");
    }
    else
    {
        n->data = val;
        n->next = NULL;
        if (f == NULL)
        {
            f = r = n;
        }
        else
        {
            r->next = n;
            r = n;
        }
    }
}

int dequeue()
{
    int val = -1;
    struct node *ptr = f;
    if (f == NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        f = f->next;
        val = ptr->data;
        free(ptr);
    }
    return val;
}

int main()
{
    enqueue(23);
    enqueue(21);
    enqueue(57);
    linkedListTraversal(f);
    printf("Dequing elements: %d\n", dequeue());
    linkedListTraversal(f);

    return 0;
}
