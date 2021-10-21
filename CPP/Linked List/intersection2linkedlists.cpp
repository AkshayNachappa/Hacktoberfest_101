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

int length(node* head){
	int k = 0;
	node* temp = head;
	while(temp!=NULL){
		k++;
		temp = temp->next;
	}
	return k;
}


void intersect(node* &head1, node* &head2, int pos){
	node* temp1 = head1;
	pos--;
	while(pos--){
		temp1 = temp1->next;
	}
	node* temp2 = head2;
	while(temp2->next != NULL){
		temp2 = temp2->next;
	}
	temp2->next = temp1;
}


int intersection(node* &head1, node* &head2){
	int l = length(head1);
	int n = length(head2);
	int x;
	node* ptr1;
	node* ptr2;
	if(l>n){
		x = l-n;
	    ptr1 = head1;
	    ptr2 = head2;
	}

	else{
		x = n-l;
		ptr1 = head2;
		ptr2 = head1;
	}
	while(x){
		ptr1 = ptr1->next;
		if(ptr1 == NULL){
			return -1;
		}
		x--;
	}
	while(ptr1 != NULL && ptr2 != NULL){
		if(ptr1 == ptr2){
			return ptr1->data;
		}
		ptr1 = ptr1->next;
		ptr2 = ptr2->next;
	}

	return -1;

}




int main(){

	node* head1 = NULL;
	insertAtTail(head1, 2);
	insertAtTail(head1, 3);
	insertAtTail(head1, 4);
	insertAtTail(head1, 5);
	insertAtTail(head1, 6);
	insertAtTail(head1, 7);

	node* head2 = NULL;
	insertAtTail(head2, 8);
	insertAtTail(head2, 9);
	insertAtTail(head2, 10);
	intersect(head1, head2, 4);

	display(head1);
	cout<<endl;
	display(head2);

	cout<<intersection(head1, head2)<<endl;



	return 0;
}