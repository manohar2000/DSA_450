#include <bits/stdc++.h>
using namespace std;

class node
{    
    public:
    int data;
    node* next;
    
        node(int d)
        {        
            data = d;
            next = NULL;
        }

};


void insertAthead(node*&head, int data)
{
    node* newnode = new node(data);
    newnode->next = head;
    head = newnode;
}


void insertAttail(node *&head, int data)
{
    if(head==NULL) insertAthead(head, data);
    else
    {
        node* newnode = new node(data);
        node* temp = head;
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }

        temp->next = newnode;
        newnode->next = NULL;
    }
}

int len(node*&head)
{
    if(head==NULL) return 0;
    else
    {
        node* temp = head;
        int len = 0;
        while(temp->next!=NULL)
        {
            temp = temp->next;
            len+=1;
        }

        return len;
    }
}

void insertAtMiddle(node*&head, int data, int p)
{

    if(head==NULL || p==0) insertAthead(head, data);
    else if(p>=len(head)) insertAttail(head,data);

    else
    {
        node* temp = head;
        while(p-1>0)
        {
            temp = temp->next;
            p-=1;
        }

        node* newnode = new node(data);
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

void deleteHead(node*&head)
{
    if(head==NULL) return;
    else
    {
        node* temp = head;
        head = head->next;
        delete temp;
    }

}

void deleteTail(node*&head)
{
    if(head==NULL) return;
    else
    {
        node* temp = head;
        while(temp->next->next!=NULL)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
    }
}

void deleteAtMiddle(node*&head, int p)
{
    if(p>len(head)) return;
    else if(p==0) deleteHead(head);
    else if(p==len(head)) deleteTail(head);
    else
    {
        node* prev;
        node* front = head;
        int i=0;
        while(i<p)
        {
            prev = front;
            front = front->next;
            i+=1;
        }

        prev->next = front->next;
        delete front;
    }

}


int main()
{
    node *head = NULL;
    insertAthead(head,50);
    insertAthead(head,100);
    insertAthead(head,200);
    insertAttail(head,500);
    insertAtMiddle(head, 75,1);


    // 200->75->100->50
    deleteAtMiddle(head, 3);
    //deleteHead(head);
    //deleteTail(head);

    node* temp = head;
    while(temp->next!=NULL)
    { 
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
    return 0;
}