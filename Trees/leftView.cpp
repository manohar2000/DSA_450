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


vector<int> leftView(node *root)
{
   vector<int> v;
   queue<node* > q;
   
   if(root==NULL) return v;
   
   else
   {
        q.push(root);
        int size;
        node* temp;
       
        while(!q.empty())
        {
            size = q.size();
            for(int i=1;i<=size;i++)
            {
                temp = q.front();
                q.pop();
                if(i==1) v.push_back(temp->data);
                
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
           
        }
       
       return v;
   }

}


int main()
{
    node* root = buildTree();
    vector<int> v;
    v = leftView(root);

    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }

    return 0;
}