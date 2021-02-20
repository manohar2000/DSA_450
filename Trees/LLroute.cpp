//Question: Given a LL representing the path from a leaf node to root, print the traversal direction from root to that leaf node

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

class LLnode
{
    public:
    int data;
    LLnode *next;

    LLnode(int d)
    {
        data = d;
        next = NULL;
    }
};

void reverseLL(LLnode*&head)
{
    LLnode* curr = head;
    LLnode* prev = NULL;
    LLnode* N;

    while(curr!=NULL)
    {
        N = curr->next;
        curr->next = prev;
        prev = curr;
        curr = N;
    }
    head = prev;
    
}

void printInorder(node* root)
{
    if(root==NULL) return;

    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}

int length(LLnode *&head)
{
    int len = 0;
    LLnode *temp = head;
    while(temp->next!=NULL)
    {
        temp = temp->next;
        len+=1;        
    }

    return len;
}

void insertAtHead(LLnode*&head, int data)
{   
    LLnode* newNode = new LLnode(data);
    newNode->next = head;
    head = newNode;
}



void insertAtTail(LLnode *&head, int data)
{
    if(head==NULL)
    {
        head = new LLnode(data);
        return;
    }

    LLnode* temp = head;    

    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    
    LLnode* tail = new LLnode(data);
    temp->next = tail;

    return;

}

void insertInMiddle(LLnode*&head, int data, int p)
{
    if(head==NULL||p==0) insertAtHead(head,data);

    if(p>length(head)) insertAtTail(head,data);

    int i = 0;
    LLnode* temp = head;
    while(i<=p-1)
    {
        temp = temp->next;
        i+=1;
    }

    LLnode* middle = new LLnode(data);
    middle->next = temp->next;
    temp->next = middle;

    return;

}

//input : 1 2 3 8 -1 -1 7 -1 9 -1 -1 -1 2 -1 5 -1 -1
// neeche ka maal asli hain, upar bakwass hain

vector<char> ans={};


void LLroute(node* root, LLnode* head)
{    
    cout<<head->data<<" ";    
    cout<<root->data<<" ";
    // cout<<" "<<root->left->data;
    // cout<<" "<<root->right->data<<endl;

    if(root==NULL || head->next==NULL) return;

    else
    {        
        int index = head->next->data;
        cout<<index<<" ";      

        // data is in the left node
        if((root->left != NULL) and (root->left->data==index))
        {    
            cout<<"left"<<endl;        
            ans.push_back('L');            
            LLroute(root->left,head->next);
        }

        // data is in the right node
        else if((root->right!=NULL) & (root->right->data==index))
        {
            cout<<"right"<<endl;
            ans.push_back('R');
            LLroute(root->right,head->next);
        }
        // node not found
        else
        {
            cout<<"not found"<<endl;
            return;
        }
    }
}

int main()
{
    node* root = buildTree();
    LLnode* head = NULL;

    insertAtHead(head,9);
    insertAtTail(head,7);
    insertAtTail(head,3);
    insertAtTail(head,2);
    insertAtTail(head,1);

    cout<<"Inorder of tree:"<<endl;    
    printInorder(root);
    cout<<endl<<"------"<<endl;


    // reversing the list
    reverseLL(head);

    LLnode* temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    
    cout<<endl<<"------"<<endl;

    LLroute(root,head);
    cout<<endl;

    for(int j=0;j<ans.size();j++)
    {
        cout<<ans[j]<<" ";
    }

    return 0;
}