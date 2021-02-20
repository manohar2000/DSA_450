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

void printPostOrder(node* root)
{    
    stack<node*> s;
    s.push(root);
 
    stack<int> out;
 
    while (!s.empty())
    {
        node *curr = s.top();
        s.pop();
 
        out.push(curr->data);
 
        if (curr->left)
            s.push(curr->left);
 
        if (curr->right)
            s.push(curr->right);
    }
 
    while (!out.empty())
    {
        cout << out.top() << " ";
        out.pop();
    }

}


int main()
{
    node* root = buildTree();
    printPostOrder(root);

    return 0;
}