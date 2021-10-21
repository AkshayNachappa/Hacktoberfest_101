#include<bits/stdc++.h>
using namespace std;


class node{
	public:
		int data;
		node* prev;
		node* next;
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

void deletion(node* &head, int pos){

	if(pos == 1){
		node* toDelete = head;
		head = head->next;
		head->prev = NULL;

		delete toDelete;
		return;
	}


	int count = 1;
	node* temp = head;

	while(temp != NULL && count != pos){
		temp = temp->next;
		count++;
	}

	temp->prev->next = temp->next;
	if(temp->next != NULL){
		temp->next->prev = temp->prev;
	}
	delete temp;
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
	deletion(head, 3);
	display(head);
	deletion(head, 1);
	display(head);


	return 0;
}