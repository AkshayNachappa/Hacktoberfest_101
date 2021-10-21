#include <bits/stdc++.h>
using namespace std;


// This is the structure of node of the linked list.
class node{

	public:
	int data;
	node* next;

	node(int val){
		data = val;
		next = NULL;
	}
};


// This function adds value to the head of the list.
void insertAtHead(node* &head, int val){
	node *n = new node(val);
	n->next = head;
	head = n;
}

//This function adds value to the tail of the list. 
void insertAtTail(node* &head, int val){
	node* n = new node(val);

	if(head==NULL){
		head=n;
		return;
	}

	node* temp = head;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=n;
}

//This function prints the entire liked list.
void display(node *head){
	node* temp = head;
	while(temp != NULL){
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<endl;
}

// This function search a specific value in the list. 
bool search(node* head, int key){
	node* temp = head;

	while(temp!=NULL){
		if(temp->data == key){
			return true;
		}
		temp = temp->next;
	}
	return false;

}

// This function deletes a specific value in the list.
void deletion(node* &head, int val){
	if (head == NULL){
		return;
	}
	node* temp = head;
	if(temp->data == val){
		node* toDelete = head;
		head = head->next;

		delete toDelete;
		return;
	}
	while(temp->next->data != val){
		temp = temp->next;
	}
	node* toDelete = temp->next;
	temp->next = temp->next->next;

	delete toDelete;
}

// This function reverses the linked list.
node* reverse(node* &head){

	node* previous = NULL;
	node* current = head;
	node* nxt;

	while(current != NULL){
		nxt = current->next;
		current->next = previous;
		previous = current;
		current = nxt;
	}
	return previous;
}

// Recursive way of reversing a linked list.
node* reverseRecursive(node* &head){
	if(head==NULL||head->next==NULL){
		return head;
	}

	node* newhead = reverseRecursive(head->next);
	head->next->next = head;
	head->next = NULL;

	return newhead;
}

// This function only reverses in the group of k nodes of linked list.
node* reverseKnodes(node* &head, int k){

	 if (!head){
        return NULL;
     }   
	node* prevptr = NULL;
	node* currptr = head;
	node* nextptr = NULL;

	int count = 0;

	while(currptr != NULL && count < k){
		nextptr = currptr->next;
		currptr->next = prevptr;
		prevptr = currptr;
		currptr = nextptr;
		count++;
	}
	if(nextptr != NULL){
		head->next = reverseKnodes(nextptr,k);
	}
	return prevptr;
}


int main(){

	// creating a linked list
	node* head = NULL;
	insertAtTail(head, 2);
	insertAtTail(head, 3);
	insertAtTail(head, 4);
	insertAtTail(head, 5);
	insertAtTail(head, 6);
	insertAtTail(head, 7);

	// List-: {NULL->} 2->3->4->5->6->7
	display(head);

	insertAtHead(head, 1);
	// List-: 1->2->3->4->5->6->7

	cout<<"Your Linked List is-:"<<endl;
	display(head);

	// Searching for 2 in the list.
	// Output-: True / 1
	cout<<search(head, 2)<<endl;

	// Deleting 4 from the list.
	deletion(head, 4);
	// Linked list-: 1->2->3->5->6->7
	cout<<"Linked List after deleting 4 is-:"<<endl;
	display(head);
	
	// Reversing the linked list.
	node* newhead=reverse(head);
	// Linked List-:7->6->5->3->2->1
	cout<<"Linked list after reversing is-:"<<endl;
	display(newhead);
	
	// Also check the recursive way of reversing the linked list.
	// node* newhead = reverseRecursive(head);
	// display(newhead);

	 node* newKhead = reverseKnodes(newhead, 2);
	 cout<<"Linked list after reversing the first two nodes-:"<<endl;
	 display(newKhead);

	return 0;
}