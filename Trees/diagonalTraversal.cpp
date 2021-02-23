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


void printDiagonal(node* root, int slope, map<int, vector<int>> &m)
{
    if(root==NULL) return;
    
    m[slope].push_back(root->data);
    
    if(root->left) printDiagonal(root->left, slope+1, m);
    if(root->right) printDiagonal(root->right, slope, m);
}


vector<int> diagonal(node *root)
{
   vector<int> v;
   if(root==NULL) return v;
   
   else
   {
        map<int, vector<int>> m;
        int slope = 0;
        printDiagonal(root, slope, m);
        
        for(auto it: m)
        {
            vector<int> v_temp = it.second;
            for(auto i:v_temp)
            {
                v.push_back(i);
            }
        }
        
        return v;
   }
}



int main()
{
    node* root = buildTree();
    vector<int> v;
    v = diagonal(root);

    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }

    return 0;
}