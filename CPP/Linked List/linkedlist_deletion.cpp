#include <iostream>
using namespace std;  


struct Node {
    int data; 
    struct Node *next; 
};

struct Node* deleteatfirst(struct Node *head) {
    head = head ->next;
    return head; 
}

struct Node* deleteatindex(struct Node *head, int index) {
    struct Node* p = head;
    struct Node* q = p->next;
    for(int i=0; i < index-1; i++) {
        p = p->next;
        q = q->next; 
    }

    p->next = q-> next; 
    free(q); 
    return head; 
}


struct Node* deleteattail(struct Node *head) {
    struct Node* p = head;
    struct Node* q = p->next;
    while(q->next!=NULL) {
        p = p->next;
        q = q->next; 
    }
    p->next =NULL; 
    free(q); 
    return head; 
}

struct Node* givenvalue(struct Node* head, int value) {
    struct Node* p = head;
    struct Node* q = p->next;

        while(q->data !=value && q->next!=NULL) {
            p = p->next;
            q = q->next; 
    }

        if(q->data==value) {
            p->next = q->next; 
            free(q);
        }
        return head; 
}
void linkedlisttraversal(struct Node *ptr) {
    while(ptr!=NULL) {
        cout<<ptr->data <<endl; 
        ptr=ptr->next;
    }
}

int main() {
    struct Node *head; 
    struct Node *second;
    struct Node *third;  
    struct Node *fourth; 

    head= (struct Node *)malloc(sizeof(struct Node));
    second= (struct Node *)malloc(sizeof(struct Node));
    third= (struct Node *)malloc(sizeof(struct Node));
    fourth= (struct Node *)malloc(sizeof(struct Node));

    head->data=7;
    head->next=second;

    second->data=12; 
    second->next=third;

    third->data=66; 
    third->next=fourth; 

    fourth->data=72; 
    fourth->next=NULL;

    linkedlisttraversal(head);
    cout<<endl;
    head= givenvalue(head,22); 
    linkedlisttraversal(head);
    return 0;
}
