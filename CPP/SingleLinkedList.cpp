#include<iostream>
using namespace std;

struct Node{
	int data;
	struct Node *next;
};

class l_list{
	Node *head;
	Node *tail;
	int len;
public:
	l_list(){
		head = new Node;
		tail = new Node;
		head = NULL;
		tail = NULL;
		len = 0;
	}

	void insert_last(int val){
		Node *temp = new Node;
		temp->data = val;
		temp->next = NULL;

		if(head == NULL){
			head = temp;
			tail = temp;
			len++;
		}else{

			tail->next = temp;
			tail = temp;
			len++;
		}
	}

	void insert(int val, int pos){
		Node *prev ;
		Node *curr ;
		prev = head;
		curr = head;
		for(int i=0;i<pos;i++){
			prev = curr;			
			curr = curr->next;
		}

		Node *temp = new Node;
		temp->data = val;
		temp->next = curr;
		prev->next = temp;
		len++;		

	}

	void display(){
		Node *temp; 
		temp = head;

		// while(temp->next != NULL){
		// 	cout<<temp->data<<" ";
		// 	temp = temp->next;
		// }
		// cout<<temp->data<<endl;

		for(int i=0;i<len;i++){
			cout<<temp->data<<" ";
			temp = temp->next;
		}

		cout<<endl;
	}

	void delete_first(){
		Node *temp = new Node;
		temp = head;
		head = head->next;
		delete temp;
		len--;
	}

	void delete_last(){
		Node *prev = new Node;
		Node *curr = new Node;
		prev = head;
		curr = head;
		for(int i=1;i<len;i++){
			prev = curr;			
			curr = curr->next;
		}
		
		prev->next = NULL;
		delete curr;
		len--;
	}

	void length(){
		cout<<"Length of Linked list is: "<<len<<endl;	
	}

	~l_list(){
	Node *p = new Node;
	Node *c = new Node;
	p = head;
	c = head;
	while(c->next != NULL){
		p = c;
		c = c->next;
		delete p;	
	}
	
	delete c;
}

};

int main(){
	l_list l;
	l.insert_last(1);
	l.insert_last(2);
	l.insert_last(3);
	l.display();
	l.length();
	l.delete_first();
	l.display();
	l.length();
	l.delete_last();
	l.display();
	l.length();
	return 0;
}