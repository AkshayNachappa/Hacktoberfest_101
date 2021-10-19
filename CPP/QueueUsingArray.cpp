#include <iostream>
using namespace std; 

template <typename T>
class QueueUsingArray{
    T *data; 
    int nextIndex;
    int firstIndex;
    int size;
    int capacity;

    public:
    QueueUsingArray(int s) {
        data = new T[s];
        nextIndex=0;
        firstIndex=-1;
        size=0;
        capacity=s;
    }

    int getsize() {
        return size; 
    }

    bool isEmpty() {
        return size==0;
    }

    void enqueue(T element) {
        if(getsize()==capacity)
            cout<<"Queue is Full";
        
        else {
        data[nextIndex] = element;
        nextIndex = (nextIndex+1)%capacity;

        if(firstIndex==-1)
            firstIndex=0;

        size++;
        }
    }

    T dequeue() {
        T ans = data[firstIndex];
        firstIndex = (firstIndex+1)%capacity;
        size--;
        return ans;
    }

    T front() {
        return data[firstIndex];
    }
};


int main() {
    QueueUsingArray <int> q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);


    cout<<endl<<q.front();
    cout<<endl<<q.dequeue();
    cout<<endl<<q.getsize();
    cout<<endl<<q.isEmpty();


    return 0;

}