
#include <iostream>
using namespace std;

#define n 50

class stack{
    int* arr;
    int top;
    
    public:
    stack()
    {
        arr=new int[n];
        top=-1;
    }
    
    void push(int x)
    {
        if(top==n-1)
        {
            cout<<" stack overflow "<<endl;
            return;
        }
        top++;
        arr[top]=x;
    }
    
    void pop()
    {
        if(top==-1)
        {
            cout<<"no element to pop"<<endl;
        }
        top--;
    }
    
    int Top()
    {
        if(top==-1)
        {
            cout<<"no element in stack"<<endl;
            return -1;
        }
        return arr[top];
    }
    
    bool empty(){
        return top==-1;
    }
};



int main(){
    cout<<"********** Welcome to Stack Operation **************" <<endl;
    int op;
    stack ds;
    cout<<"\n\nSelect an option to continue: " <<endl;

    while(1){
        cout<<"\n\n\n\nPress '0' to Exit()" <<endl
            <<"\nPress '1' to check if Stack is Empty" <<endl
            <<"\nPress '2' to get the Top element" <<endl
            <<"\nPress '3' to Push an element" <<endl
            <<"\nPress '4' to Pop an element" <<endl
            <<"\n\n\t\t>> ";
        cin>>op;

        switch(op){
            case 0:
                cout<<"\n\nHope to see you again!" <<endl;
                exit(0);
                break;

            case 1:
                if(ds.empty()){
                    cout<<"\n\nStack is Empty \nYou reached the end of the World." <<endl;
                }
                else{
                    cout<<"\n\nStack has some space Occupied." <<endl;
                }
                break;

            case 2:
                cout<<"\n\nTopmost element in Stack is: " <<ds.Top();
                break;

            case 3:
                cout<<"\nEnter the value to be Pushed into the Stack: ";
                cin>>op;
                ds.push(op);
                break;

            case 4:
                ds.pop();
                break;
                
            default:
                cout<<"\n\nPlease enter a valid option 0-4" <<endl;
        }
    }
    

    return 0;
}
