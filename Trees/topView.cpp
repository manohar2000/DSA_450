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

// the idea is to have an queue of type<node, hd> and store elements in bfs order.
// Have a map with the hd as the key and their corresponding nodes. 
// Finally, the first value of each key will be give the top for the particular hd.


// for bottom view, we just need to replace the value of hd with new value, if encoutered

vector<int> topView(node* root)
{
    vector<int> v;
    if(root==NULL) return v;
    
    else
    {
        queue<pair<node*, int>> q;
        map<int, int> m;
        q.push(make_pair(root, 0));
        
        while(!q.empty())
        {
            pair<node*, int> front = q.front();
            q.pop();

            // for bottom view :
            // m[front.second] = front.first->data; instead of the below if condition

            if(m.find(front.second)==m.end())
            {
                m[front.second] = front.first->data;
            }

            
            if(front.first->left) q.push(make_pair(front.first->left, front.second-1));
            if(front.first->right) q.push(make_pair(front.first->right, front.second+1));
            
            
        }
        
        map<int, int> :: iterator it;
        int temp;
        for(it=m.begin();it!=m.end();it++)
        {
            v.push_back(it->second);
        }
        return v;
    }

    

}


int main()
{
    node* root = buildTree();
    vector<int> v;
    v = topView(root);

    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }

    return 0;
}