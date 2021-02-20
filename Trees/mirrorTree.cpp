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
    if(root==NULL) return;

    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}

void mirror(node* root)
{
    if(root==NULL) return;

    else
    {
        if(root->left && root->right)
        {
            node* temp = root->left;
            root->left = root->right;
            root->right = temp;

            mirror(root->left);
            mirror(root->right);
        }

        else if(root->left && !root->right)
        {
            root->right = root->left;
            root->left = NULL;
            mirror(root->right);
        }

        else if(!root->left && root->right)
        {
            root->left = root->right;
            root->right = NULL;
            mirror(root->left);
        }

    }
}



int main()
{
    node* root = buildTree();
    printInorder(root);

    mirror(root);
    cout<<endl;
    printInorder(root);

    return 0;
}