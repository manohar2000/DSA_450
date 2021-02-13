#include <bits/stdc++.h>
using namespace std;
 
class node {
public:
    int data;
    node* left;
    node* right;
    node(int x)
    {
        data = x;
        left = right = NULL;
    }
};


void printInorder(node* root)
{
    if(root==NULL) return;

    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}


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


void mergeBST(node* root1, node* root2)
{
    if(!root1 && !root2) return;

    if(!root1)
    { 
        printInorder(root2);
        return;
    }

    if(!root2)
    {
        printInorder(root1);
        return;
    }

    // prev will store the parent of the curr node
    node* temp1 = root1;
    node* prev1 = NULL;

    // traverse to the leftmost node of tree1
    while(temp1->left)
    {
        prev1 = temp1;
        temp1 = temp1->left;
    }

    node* temp2 = root2;
    node* prev2 = NULL;

    // traverse the leftmost node of tree2
    while(temp2->left)
    {
        prev2 = temp2;
        temp2 = temp2->left;
    }


    // checking whose value is less
    if(temp1->data<=temp2->data)
    {
        cout<<temp1->data<<" ";

        // if we are at the root node
        if(prev1==NULL) mergeBST(root1->right, root2);

        // removing the pointer to this left node and moving it either to a null ptr or the right node
        else
        {
            prev1->left = temp1->right;
            mergeBST(root1, root2);
        }

    }

    else
    {
        cout<<temp2->data<<" ";

        if(prev2==NULL) return mergeBST(root1, root2->right);

        else
        {
            prev2->left = temp2->right;
            mergeBST(root1, root2);
        }
    }    

}


int main()
{
    node* root1 = buildTree();
    node* root2 = buildTree();
    
    mergeBST(root1, root2);
    return 0;
}