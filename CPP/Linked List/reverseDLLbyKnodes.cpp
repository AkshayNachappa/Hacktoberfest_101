#include<bits/stdc++.h>
using namespace std;

class node{
	public:
		int data;
		node* next;
		node* prev;
		node(int val){
			data = val;
			next = NULL;
			prev = NULL;
		}
};

void insertAtHead(node* &head, int val){
	node* n = new node(val);

	n->next = head;
	if(head != NULL){
		head->prev = n;
	}
	head = n;
}

void insertAtTail(node* &head, int val){
	node* n = new node(val);
	node* temp = head;
	
	if(head == NULL){
		
		n->next = head;
		head = n;
		return;
	}

	while(temp->next != NULL){
		temp = temp-> next;
	}
	temp->next = n;
	n->prev = temp;
}

void display(node* &head){
	node* temp = head;
	while(temp!=NULL){
		cout<<temp->data<<"->";
		temp = temp->next;
	}cout<<"NULL"<<endl;
}




node* reverseKnodes(node* &head, int k){
	node* nextptr;
	node* prevptr = NULL;
	node* curptr = head;
	int count = 0;

	while(curptr != NULL && count<k){
		nextptr = curptr->next;
		curptr->next = prevptr;
		prevptr = curptr;
		curptr = nextptr;
		count++;
	}

	if(nextptr != NULL){
		head->next = reverseKnodes(nextptr, k);
	}
	return prevptr;
}


int main(){

	node* head = NULL;
	insertAtTail(head, 1);
	insertAtTail(head, 2);
	insertAtTail(head, 3);
	insertAtTail(head, 4);
	insertAtTail(head, 5);
	insertAtHead(head, 0);
	display(head);
	node* newhead = reverseKnodes(head, 2);
	display(newhead);



	return 0;
}