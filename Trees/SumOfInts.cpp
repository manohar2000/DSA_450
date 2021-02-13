// Given a BST we need to check if all the root nodes value is the average 
// of its left and right node. If the condition is false then delete the root node.
// Return a BST that follows the above condition.

/*
Solution: Recursion. Calling the func with the multiplier of 10 and
multiplying the left/right int with the multiplier. If we reach a null then push the no. to an vector.
Lastly taking the sum of the elements in the array
*/



/// !! NOT WORKING


#include <bits/stdc++.h>
using namespace std;

vector<int> v = {};

class node {
public:
    int data;
    node* left;
    node* right;
    node(int x)
    {
        data = x;
        left = right = NULL;
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


void bfs(node* root)
{
    queue<node*> q;
    q.push(root);
    q.push(NULL); // to print every level in new lines

    while(!q.empty())
    {
        node* f = q.front();

        // including null after every level. We will print normally and will add a null only when previous level's nodes have been printed completely.
        if(f==NULL)
        {
            q.pop();
            if(!q.empty())
            {
                cout<<endl;
                q.push(NULL); // we add null only until the queue is not empty, else it will become an infinite loop/
            }
        }

        else
        {
            q.pop();
            cout<<f->data<<" ";        

            if(f->left) q.push(f->left);

            if(f->right) q.push(f->right);
        }
    }
}


void sumOfNodes(node* root, int num, int level)
{    

    if(root==NULL)
    {
        v.push_back(num);
        return;
    }


    else if(root->left && !root->right)
    {
        num+= root->data*(pow(10,level));
        sumOfNodes(root->left, num, level+1);
    }

    else if(!root->left && root->right)
    {
        num+= root->data*(pow(10,level));
        sumOfNodes(root->right, num, level+1);
    }


    else
    {
        num+= root->data*(pow(10,level));
        // calling left subtree        
        sumOfNodes(root->left, num, level+1);

        //calling right subtree
        sumOfNodes(root->right, num, level+1);
    }


}



int main()
{
    node* root = buildTree();
    cout<<"bfs:"<<endl;
    bfs(root);
    cout<<endl<<"----------"<<endl;

    int num = 0;
    int level = 0;
    sumOfNodes(root,num,level);

    cout<<endl;
    for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
    return 0;
}