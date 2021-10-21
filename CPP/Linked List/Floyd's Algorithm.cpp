#include<bits/stdc++.h>
using namespace std;


class node{
public:
	int data;
	node* next;
	node(int val){
		data = val;
		next = NULL;
	}
};


void insertAtTail(node* &head, int val){
	node* n = new node(val);
	if(head == NULL){
		head = n;
		return;
	}
	
	node* temp = head;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=n;
}

void display(node *head){
	node* temp = head;
	while(temp != NULL){
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<endl;
}


void makeCycle(node* &head, int pos){
	node* temp = head;
	node* starnode;

	int count = 1;
	while(temp->next != NULL){
		if (count == pos){
			starnode = temp;
		}
		temp = temp->next;
		count++;
	}
	temp->next = starnode;
}

bool detectCycle(node* &head){
	node* slow = head;
	node* fast = head;

	while(fast != NULL && fast->next != NULL){
		fast = fast->next->next;
		slow = slow->next;

		if(fast==slow){
			return true;
		}
	}
	return false;

}
void removeCycle(node* &head){
	node* slow = head;
	node* fast = head;

	do{
		slow = slow->next;
		fast = fast->next->next;
	}while(slow != fast);

	
    struct Node* ptr1 = slow;
    struct Node* ptr2 = slow;
 
  
    unsigned int k = 1, i;
    while (ptr1->next != ptr2) {
        ptr1 = ptr1->next;
        k++;
    }
 
    // Fix one pointer to head
    ptr1 = head;
 
    // And the other pointer to k nodes after head
    ptr2 = head;
    for (i = 0; i < k; i++)
        ptr2 = ptr2->next;
 
    /*  Move both pointers at the same pace,
      they will meet at loop starting node */
    while (ptr2 != ptr1) {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
 
    // Get pointer to the last node
    while (ptr2->next != ptr1)
        ptr2 = ptr2->next;
 
    /* Set the next node of the loop ending node
      to fix the loop */
    ptr2->next = NULL;
} 

int main(){

	node* head = NULL;
	insertAtTail(head, 1);
	insertAtTail(head, 2);
	insertAtTail(head, 3);
	insertAtTail(head, 4);
	insertAtTail(head, 5);
	insertAtTail(head, 6);
	display(head);

	cout<<detectCycle(head)<<endl;

	makeCycle(head, 4);
	cout<<detectCycle(head)<<endl;
	removeCycle(head);
	cout<<detectCycle(head)<<endl;
	display(head);

	return 0;
}