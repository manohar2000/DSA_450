/*
Given a BST we need to check if all the root nodes value is the average
of its left and right node.
*/

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

class avgpair
{
    public:
        int data = 0;
        bool balanced = false;
};


avgpair average(node* root)
{
    avgpair p;
    if(root->left==NULL && root->right==NULL)
    {
        p.data = root->data;
        p.balanced = true;
        return p;
    }

    else if((root->left==NULL) && root->right)
    {
        p.balanced = false;
        p.data = root->data;
        return p;
    }

    else if(root->left && (root->right==NULL))
    {
        p.balanced = false;
        p.data = root->data;
        return p;
    }


    avgpair left = average(root->left);
    avgpair right = average(root->right);

    if( left.balanced && right.balanced && (((left.data + right.data)/2)==root->data))
    {
        p.data = root->data;
        p.balanced = true;
        return p;        
    }

    else
    {
        p.balanced = false;
        return p;
    }

    return p;

}

int main()
{
    node* root = buildTree();
    printInorder(root);

    cout<<endl;
    avgpair p = average(root);
    cout<<p.balanced<<endl;
    return 0;
}