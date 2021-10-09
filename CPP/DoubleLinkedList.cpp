#include<iostream>
using namespace std;

struct Node{
	int data;
	Node *next;
	Node *prev;
};

class d_list{
	Node *head, *tail;
	int len;

public:
	d_list(){
		head = NULL;
		tail = NULL;
		len = 0;
 	}

	void insert_last(int val){
		Node *temp = new Node;
		temp->data = val;

		if(head == NULL){
			temp->prev = NULL;
			temp->next = NULL;
			head = temp;
			tail = temp; 
			len++;
		}else{
			tail->next = temp;
			temp->prev = tail;
			temp->next = NULL;
			tail = temp;
			len++;
		}
	}

	void insert(int val, int pos){
		Node *temp;
		temp = head;

		for(int i=1;i<pos;i++){
			temp = temp->next;
		}

		Node *dat = new Node;
		dat->data = val;
		dat->next = temp->next;
		temp->next->prev = dat;
		temp->next = dat;
		dat->prev = temp;
		len++;
	}

	void delete_last(){
		Node *temp;
		temp = tail;
		tail = tail->prev;
		delete temp;
		len--;
	}

	void delete_first(){
		Node *temp;
		temp = head;
		head = head->next;
		delete temp;
		len--;
	}

	void display(){
		Node *temp;
		temp = head;

		for(int i=0;i<len;i++){
			cout<<temp->data<<" ";
			temp = temp->next;
		}

		cout<<endl;
	}
};

int main(){
	d_list d;
	d.insert_last(1);
	d.insert_last(2);
	d.insert_last(3);
	d.display();
	d.insert(5,1);
	d.display();
	d.delete_first();
	d.display();
	d.delete_last();
	d.display();
	return 0;
}