#include<bits/stdc++.h> 
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


void horizontalMap(node* root, map<int, vector<int>> &m, int hd)
{
    if(root==NULL) return;

    m[hd].push_back(root->data);

    horizontalMap(root->left, m, hd-1);
    horizontalMap(root->right, m, hd+1);
}

vector <int> zigZagTraversal(node* root)
{
    vector<int> v;
    stack<node* > curr;
    stack<node* > next;
    int leftToRight = 1;
    node* temp;
    
    if(root==NULL) return v;
    
    else
    {
        curr.push(root);
        while(!curr.empty())
        {
            temp = curr.top();
            v.push_back(temp->data);
            curr.pop();
            
            if(leftToRight)
            {
                if(temp->left) next.push(temp->left);
                if(temp->right) next.push(temp->right);
            }
            
            if(!leftToRight)
            {
                if(temp->right) next.push(temp->right);
                if(temp->left) next.push(temp->left);
            }
            
            if(curr.empty())
            {
                leftToRight = !leftToRight;
                swap(curr,next);
            }
        }
        return v;
    }
    
}




int main()
{
    node* root = buildTree();
    vector<int> v;
    v = zigZagTraversal(root);

    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }

    return 0;
}