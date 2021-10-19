#include <iostream>
using namespace std; 

template <typename T>
class Node {
    public:
    T data;
    Node <T> *next;

    Node(T data) {
        this->data = data; 
        next = NULL;
    }
};

template <typename T>
class Queue {
    public:
    Node <T> *head;
    Node <T> *tail;
    int size;

    Queue() {
        head = NULL;
        tail= NULL;
        size=0;
    }

    int getsize(){
        return size;
    }

    bool isEmpty(){
        return size == 0;
    }

    void enqueue(T element){
        Node <T> *newNode = new Node(element);
        if(head=NULL) {
            head = newNode;
            tail = newNode;
        }

        else {
            tail->next = newNode; 
            tail = newNode;
        }
        size++;
    }

    T front() {
       return head->data; 
    }

    T dequeue(){
        Node <T> *temp = head; 
        T ans = temp->data;
        head = head->next;
        delete temp;
        return ans;
        size--;
    }
};