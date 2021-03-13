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

int height(node* root)
{
    if(root==NULL) return -1;

    else  return max( height(root->left), height(root->right)) + 1;
}


int diameter(node* root)
{
    if(root==NULL) return 0;

    int lh = height(root->left);
    int rh = height(root->right);
    int op1 = lh+rh;

    int op2 = diameter(root->left);
    int op3 = diameter(root->right);

    return max(op1,max(op2,op3));
    

}


int main()
{
    node* root = buildTree();
    vector<int> v;
    cout<< height(root) <<endl;

}