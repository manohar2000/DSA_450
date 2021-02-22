#include<bits/stdc++.h> 
using namespace std; 

// Time complexity - O(nlog(n)), space complexity O(n)
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


void verticalTraversal(node* root)
{
    map<int, vector<int> > m;
    int hd = 0;
    horizontalMap(root, m, hd);

    map<int, vector<int> > :: iterator it;

    for(it=m.begin();it!=m.end();it++)
    {
        for(int i=0;i<it->second.size();i++)
        {
            cout<< it->second[i]<<" ";
        }
        cout<<endl;
    }

}



int main()
{
    node* root = buildTree();
    verticalTraversal(root);    

    return 0;
}