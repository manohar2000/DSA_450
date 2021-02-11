// A C++ program to remove BST keys outside the given range
#include<bits/stdc++.h>
 
using namespace std;
 
struct node
{
    int key;
    struct node *left;
    struct node *right;
};



node* newNode(int num)
{
    node* temp = new node;
    temp->key = num;
    temp->left = temp->right = NULL;
    return temp;
}
 
node* insert(node* root, int key)
{
    if (root == NULL)
       return newNode(key);
    if (root->key > key)
       root->left = insert(root->left, key);
    else
       root->right = insert(root->right, key);
    return root;
}
 
void inorderTraversal(node* root)
{
    if (root)
    {
        inorderTraversal( root->left );
        cout << root->key << " ";
        inorderTraversal( root->right );
    }
}

node* removeOutsideRange(node* root, int low, int high)
{
    if(root==NULL) return root;

    root->left  = removeOutsideRange(root->left,low,high);
    root->right = removeOutsideRange(root->right,low,high);

    if((root->key<low || root->key>high))
    {
        // node has no children
        if(root->left==NULL && root->right==NULL)
        {
            delete root;
            return NULL;
        }

        // node only has left child 
        if(root->left!=NULL && root->right==NULL)
        {
            node* temp = root->left;
            delete root;
            return temp;
        }

        // node only has right child
        if(root->left==NULL && root->right!=NULL)
        {
            node* temp = root->right;
            delete root;
            return temp;
        }

        // node has both the children
        if(root->left!=NULL && root->right!=NULL)
        {
            node* temp = root->left;
            delete root;
            return temp;
        }
    }
     
    return root;

}


 int main()
{
    node* root = NULL;
    root = insert(root, 6);
    root = insert(root, -13);
    root = insert(root, 14);
    root = insert(root, -8);
    root = insert(root, 15);
    root = insert(root, 13);
    root = insert(root, 7);
 
    cout << "Inorder traversal of the given tree is: ";
    inorderTraversal(root);
 
    root = removeOutsideRange(root, -10, 13);
 
    cout << "\nInorder traversal of the modified tree is: ";
    inorderTraversal(root);
 
    return 0;
}