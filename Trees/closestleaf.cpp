// Question: Given Two BST we were supposed to print the sorted order of the nodes from both of the best combined in O(1) space and
// there was a catch that each node had reference to its  left child, right child, and parent node

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



int closestLeaf(node* root)
{
    if(root==NULL) return 0;
    
    else if(root->left && !root->right) return closestLeaf(root->left) + 1;

    else if(!root->left && root->right) return closestLeaf(root->right) + 1;

    else
    {
        int leftLen = closestLeaf(root->left) + 1;
        int rightLen = closestLeaf(root->right) + 1;

        return min(leftLen,rightLen);
    }
}


void printInorder(node* root)
{
    if(root==NULL) return;

    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}

int main()
{
    node* root = buildTree();
    printInorder(root);
    cout<<endl;

    cout<<closestLeaf(root)-1<<endl;

    return 0;
}