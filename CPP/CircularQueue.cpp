#include<iostream>
using namespace std;

struct Node{
	int data;
	Node *link;
};

class queue{
	Node *top;
	int len;
public:
	queue(){
		top = NULL;
		len = 0;
	}	

	void push(int val){
		Node *temp = new Node;
		temp->data = val;
		temp->link = top;
		top = temp;
		len++;
	}

	void pop(){
		Node *prev, *curr;
		prev = top;
		curr = top;
		if(len != 0){
			for(int i=1;i<len;i++){
				prev = curr;
				curr = curr->link;
			}

			cout<<"Popped data is "<<curr->data<<endl;
			prev->link = NULL;
			delete curr;
			len--;
		}else{
			cout<<"Queue is empty !!!"<<endl;
		}
	}
};

int main(){
	queue q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.pop();
	q.pop();
	q.pop();
	q.pop();
	return 0;
}