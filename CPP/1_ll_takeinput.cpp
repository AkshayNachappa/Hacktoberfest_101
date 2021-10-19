#include <iostream>

using namespace std ;

class Node {
    public:
    int data; 
    Node *next; 

    Node (int data) {
    this->data=data; 
    next=NULL;
    }
};

Node* takeinput(){
    int data; 
    cin>>data; 

    Node *head = NULL;
    Node *tail = NULL; 

    while(data !=-1) {
        Node *newnode = new Node(data); 

        if(head==NULL){
            head=newnode; 
            tail=newnode; 
        }

        else {
            tail->next = newnode; 
            tail = newnode; 
        }
    cin>>data;
    }
    return head;
}

void printll(Node *head) {
    while(head !=NULL ) {
        cout<<head->data <<endl;
        head=head->next; 
    }
}
int main() {
    Node *head = takeinput(); 
    cout<<endl;
    printll(head);
    return 0; 
}