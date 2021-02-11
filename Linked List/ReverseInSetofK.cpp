/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
    struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    }*head;
*/


// SOLVED IN GFG
struct node *reverse (struct node *head, int k)
{ 
    node* prev = NULL;
    node* curr = head;
    node* next;
    int i = 1;
    node* start = head;
    while(curr!=NULL && i<=k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        i++;
    }
    if(next!=NULL)
    {
        head->next = reverse(next,k);
    }
    head = prev;
    return head;
}