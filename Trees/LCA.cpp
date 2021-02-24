/* The goal is to find the lowest common ancestor for two nodes in a BT
Solution: The idea is to store the path from root to each node and store it in an vector/array.
After we've got both the arrays we'll traverse both the arrays until the nodes are matching.
The indice after which the values will change is the LCA
*/

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


bool routeToNode(node* root, int key, vector<int> &v)
{
    if(root==NULL) return false;

    // push the elements in the vector
    v.push_back(root->data);

    // if the root==key then exit out of the function
    if(root->data==key) return true;

    // if key is present in either the left or right subtree then vector will have elements till that and would exit out of the loop
    if( (root->left && routeToNode(root->left,key,v)) || (root->right && routeToNode(root->right,key,v))) return true;

    // if element is not present in BT then remove the last element and return false
    v.pop_back();
    return false;

}

int LCA(node* root, int key1, int key2)
{
    if(root==NULL) return -1;

    else
    {
        vector<int> v1;
        vector<int> v2;

        if( !routeToNode(root,key1,v1) || !routeToNode(root,key2,v2) ) return -1;

        // traverse both the vectors and check for the LCA
        int LCA = -1;
        
        for(int i=0; i<min(v1.size(),v2.size()); i++)
        {        
            if(v1[i]==v2[i]) LCA = v1[i];
            else break;

        }

        return LCA;
    }
}


int main()
{
    node* root = buildTree();
    int key1;
    cin>>key1;

    int key2;
    cin>>key2;

    cout<<LCA(root, key1, key2)<<endl;    
}