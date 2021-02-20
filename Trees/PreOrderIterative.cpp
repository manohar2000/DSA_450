#include <bits/stdc++.h>
using namespace std;

class node
{
    public:
        int data;
        node* left;
        node* right;

        node(int d)
        {
            data = d;
            left = NULL;
            right = NULL;
        }
};


node* buildTree()
{
    int d;
    cin>>d;

    if(d==-1) return NULL;

    else
    {
        node* root = new node(d);
        root->left = buildTree();
        root->right = buildTree();

        return root;
    }    
}


void printPreOrder(node* root)
{
    node* curr;
    stack<node* > s;
    s.push(root);
    while(!s.empty())
    {
        curr = s.top();
        s.pop();
        cout<<curr->data<<" ";

        if(curr->right) s.push(curr->right);
        if(curr->left) s.push(curr->left);

    }
}



int main()
{
    node* root = buildTree();
    printPreOrder(root);

    return 0;
}