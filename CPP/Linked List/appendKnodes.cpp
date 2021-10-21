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

void insertAtHead(node* &head, int val){
	node *n = new node(val);
	n->next = head;
	head = n;
}

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

void display(node *head){
	node* temp = head;
	while(temp != NULL){
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<endl;
}


int length(node* &head){
	node* temp = head;
	int l = 0;

	while(temp!= NULL){
		temp = temp->next;
		l++;
	}
	return l;
}

node* knodeAppend(node* &head, int k){
	node* newhead;
	node* newtail;
	node* temp = head;

	int l = length(head);
	k=k%l;
	int count = 1;
	while(temp->next != NULL){
		if(count == l-k){
			newtail = temp;
		}
		if(count == l-k+1){
			newhead = temp;
		}
		temp = temp->next;
		count++;
	}
	temp->next = head;
	newtail->next = NULL;
	return newhead;
}


int main(){
	node* head = NULL;
	insertAtTail(head, 1);
	insertAtTail(head, 2);
	insertAtTail(head, 3);
	insertAtTail(head, 4);
	insertAtTail(head, 5);
	display(head);
	node* newhead = knodeAppend(head, 3);
	display(newhead);


}