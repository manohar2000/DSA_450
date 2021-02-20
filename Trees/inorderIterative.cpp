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

void printInorder(node* root)
{
    stack<node* > s;
    node* curr;
    while(curr!=NULL || !s.empty())
    {
        if(curr!=NULL)
        {
            s.push(curr);
            curr = curr->left;
        }

        else
        {
            curr = s.top();
            s.pop();
            cout<<curr->data<<" ";
            curr = curr->right;
        }
    }

}

int main()
{
    node* root = buildTree();
    printInorder(root);

    return 0;
}