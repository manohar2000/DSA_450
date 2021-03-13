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



int main()
{
    node* root = buildTree();
    vector<int> v;
    cout<< height(root) <<endl;

}