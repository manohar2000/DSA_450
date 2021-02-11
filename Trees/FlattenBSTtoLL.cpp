#include <iostream>
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


node* insertinBST(node* root, int data)
{
    if(root==NULL)
    { 
        return new node(data);
    }

    if(data<=root->data)
    {
        root->left = insertinBST(root->left,data);
    }

    else
    {
        root->right = insertinBST(root->right,data);
    }

    return root;
}


class LinkedList
{
    public:
        node* head;
        node* tail;
};


LinkedList FlattenBST(node* root)
{
    LinkedList l;
    if(root==NULL) 
    {
        l.head=l.tail=NULL;
        return l;
    }

    // if root is a leaf node
    else if(root->left==NULL && root->right==NULL) 
    {
        l.head=l.tail=root;
        return l;
    }

    // if root has a left child only
    else if(root->left!=NULL && root->right==NULL)
    {
        LinkedList leftll = FlattenBST(root->left);
        l.head = leftll.head;
        l.tail = root;
        leftll.tail->right = root;

        return l;
    }


    // if root has a right child only
    else if(root->left==NULL && root->right!=NULL)
    {
        LinkedList rightll = FlattenBST(root->right);
        root->right = rightll.head;
        l.head = root;
        l.tail = rightll.tail;
        return l;
    }

    // if root has both the children

    LinkedList leftll = FlattenBST(root->left);
    LinkedList rightll = FlattenBST(root->right);

    leftll.tail->right = root;
    l.head = leftll.head;
    root->right = rightll.head;
    l.tail = rightll.tail;
    return l;

}


node* build()
{
    int d;
    cin>>d;
    
    node* root = NULL;

    while(d!=-1)
    {
        root = insertinBST(root, d);
        cin>>d;
    }

    return root;
}



int main()
{

    node* root = build();

    LinkedList l = FlattenBST(root);

    node*temp = l.head;

    while(temp!=NULL)
    {
        cout<<temp->data<<"--->";
        temp = temp->right;
    }
    cout<<endl;

    return 0;
}