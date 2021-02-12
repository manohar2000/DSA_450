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

vector<int> inorder(node* root, vector<int> &v)
{
    
    if(root==NULL) return v;
    
    inorder(root->left, v);
    v.push_back(root->data);
    
    inorder(root->right, v);

    return v;
}

bool inorderSame(node* root1, node* root2)
{
    vector<int> v1 = {};
    v1 = inorder(root1, v1);
    vector<int> v2 = {};
    v2 = inorder(root2, v2);

    for(int i=0; i<v1.size();i++)
    {
        if(v1[i]!=v2[i]) return false;
    }

    return true;
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
    node* root1 = buildTree();
    node* root2 = buildTree();
    cout<<inorderSame(root1, root2);
    return 0;
}