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


vector<int> reverseLevelOrder(node *root)
{
    queue<node*> q;
    stack<node*> s;
    vector<int> v;
    
    q.push(root);
    s.push(root);
    
    while(!q.empty())
    {
        node* temp;
        temp = q.front();
        q.pop();
        if(temp->right)
        {
            q.push(temp->right);
            s.push(temp->right);
        }
        if(temp->left)
        {
            q.push(temp->left);
            s.push(temp->left);
        }
        
    }
    
    while(!s.empty())
    {
        node* temp = s.top();
        v.push_back(temp->data);
        s.pop();
    }
    
    return v;
    
}

int main()
{
    node* root = buildTree();
    vector<int> v;
    v = reverseLevelOrder(root);
    for(int i=0;i<v.size();i++) 
    {
        cout<<v[i]<<" ";
    }
    return 0;
}