#include<iostream>
using namespace std;

struct Node{
        int data;
        Node *next;
};

class circular_ll{
        Node *head, *tail;
        int len;
public:
        circular_ll(){
                head = new Node;
                tail = new Node;
                head = NULL;
                tail = NULL;
                len = 0;
        }

        void insert_last(int val){
                Node *temp = new Node;
                temp->data = val;

                if(head == NULL){
                        temp->next = temp;
                        head = temp;
                        tail = temp;
                        len++;
                }else{
                        tail->next = temp;
                        temp->next = head;
                        tail = temp;
                        len++;
                }
        }

        void delete_last(){
                Node *prev, *curr;
                prev = head;
                curr = head;

                for(int i=1;i<len;i++){
                        prev = curr;
                        curr = curr->next;
                }

                prev->next = head;
                tail = prev;
                delete curr;
                len--;
        }

        void delete_first(){
                Node *temp;
                temp = head;
                tail->next = head->next;
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

                cout<<endl<<"length: "<<len<<endl;
        }

};

int main(){
        circular_ll c;
        c.insert_last(1);
        c.insert_last(2);
        c.insert_last(3);
        c.display();
        c.delete_last();
        c.insert_last(4);
        c.insert_last(9);
        c.display();
        c.delete_first();
        c.display();
        return 0;
}