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

void levelOrderTraversal(node* root)
{
    queue<node* > q;
    node* temp;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        temp = q.front();        
        q.pop();

        if(temp==NULL)
        {
            if(!q.empty())
            {
                cout<<endl;
                q.push(NULL);
            }

        }

        else
        {
            cout<<temp->data<<" "; 
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right); 
        }    

    }

}



int main()
{
    node* root = buildTree();
    levelOrderTraversal(root);
    return 0;
}