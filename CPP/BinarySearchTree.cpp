#include <iostream>
#include <stdlib.h>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
} * root;

class BST
{
public:
    BST()
    {
        root = NULL;
    }

    void insert(node *parent, node *leaf)
    {
        if (root == NULL)
        {
            root = leaf;
            root->data = leaf->data;
            root->left = NULL;
            root->right = NULL;
            return;
        }

        if (parent->data >= leaf->data)
        {
            if (parent->left != NULL)
            {
                insert(parent->left, leaf);
                return;
            }
            else
            {
                parent->left = leaf;
                leaf->left = NULL;
                leaf->right = NULL;
                return;
            }
        }
        if (parent->data < leaf->data)
        {
            if (parent->right != NULL)
            {
                insert(parent->right, leaf);
                return;
            }
            else
            {
                parent->right = leaf;
                leaf->left = NULL;
                leaf->right = NULL;
                return;
            }
        }
    }

    void display(node *parent)
    {
        if (parent != NULL)
        {
            display(parent->left);           //L
            cout << parent->data << " ";     //V
            display(parent->right);          //R
        }
        else
        {
            return;
        }
    }

    void tree(node *parent, int l)
    {
        if (parent != NULL)
        {
            tree(parent->right, l + 1);
            if (l == 1)
            {
                cout << "R->";
            }
            for (int i = 1; i < l; i++)
            {
                cout << "\t";
            }
            cout << parent->data << endl;
            tree(parent->left, l + 1);
        }
        else
        {
            return;
        }
    }

    void search(node *parent, int key){
        if(parent != NULL){
            if(key > parent->data){
                search(parent->right, key);
            }
            if(key < parent->data){
                search(parent->left, key);
            }
            if(key == parent->data){
                cout<<"Key Found!"<<endl;
                return;
            }
        }else{
            cout<<"Key not found"<<endl;
            return;
        }
    }
};

int main()
{
    BST t;
    int choice;
    node *temp;

    cout<<"1.Insert\t2.Display\t3.Tree\t4.Exit\n5.Search\n";

    while (true)
    {
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "INSERT: ";
            temp = new node;
            cin >> temp->data;
            t.insert(root, temp);
            break;

        case 2:
            cout << "DISPLAY BST: "<<endl;
            t.display(root);
            cout<<endl;
            break;

        case 4:
            exit(0);

        case 3:
            t.tree(root, 1);
            break;
        case 5:
            int i;
            cout<<"Enter Key: ";
            cin>>i;
            t.search(root,i);
        }
    }
    return 0;
}