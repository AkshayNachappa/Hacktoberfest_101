#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
    
};

Node* createNode(int n)
{
    Node *node = new Node;
    node->data = n;
    node->left = node->right = NULL;

    return node;
}
void display(Node *root)
{
    if(root!=NULL)
    {
        
        cout<<root->data<<" ";
        display(root->left);
        display(root->right);
    }
}
bool searchNode(Node * &root,int n)
{
    if(root==NULL)
        return false;
    else if(n==root->data)
        return true;
    else if(n<=root->data)
        return searchNode(root->left,n);
    else if(n>root->left->data)
    {
            return searchNode(root->right,n);
    }
       

}
int main()
{
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    display(root);
    int x;
    cout<<"Enter the number to search"<<endl;
    cin>>x;
    if(searchNode(root,x))
        cout<<"Number "<<x<<" found";
    else
        cout<<"Number "<<x<<" not found";

    return 0;

}



