#include <iostream>
#include <stack>
using namespace std; 



void reversestack (stack<int> &s1) {
    stack<int> s2;
    int x;
    while(!s1.empty()) {
        x=s1.top();
        s2.push(x);
        s1.pop();
    }
    s1=s2;

}
 

int main() {
    stack<int> s1; 
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);

    reversestack(s1);
    cout<<s1.top() <<endl;
    s1.pop();
    cout<<s1.top() <<endl;
     s1.pop();
    cout<<s1.top() <<endl;
     s1.pop();
    cout<<s1.top() <<endl;
    return 0;
}