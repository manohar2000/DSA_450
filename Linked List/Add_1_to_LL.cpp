/*
A number N is represented in Linked List such that each digit corresponds to a node in linked list. 
You need to add 1 to it.
*/
#include <bits/stdc++.h>
using namespace std;

void showlist(list <int> g) 
{ 
    list <int> :: iterator ite; 
    for(ite = g.begin(); ite != g.end(); ++ite) cout<<*ite<<" ";
    cout<<endl; 
}

void addition(list<int> l)
{
    l.reverse();    

    list<int> :: iterator it;
    it = l.begin();

    int sum = *it+1;
    int digit = sum%10;
    int carry = sum/10;

    *it = digit;
    
    if(carry!=0)
    {        
        it++;
        while(carry!=0 && it!=l.end())
        {   
            sum = *it + carry;
            digit = sum%10;
            carry = sum/10;
            *it = digit;
            it++;
        }
    }

    if(carry!=0 && it==l.end()) l.push_back(1);

    l.reverse(); 
    showlist(l);   
}

// mutiply number by 4
void multiplication(list<int> l)
{
    l.reverse();

    list<int> :: iterator it;
    it = l.begin();
    int product = *it * 4;
    int digit = product%10;
    int carry = product/10;

    *it = digit;
    it++;

    while(it!=l.end())
    {
        product = *it*4;
        digit = product%10;
        carry = product/10;

        *it = digit;
        it++;
    }
    

    if(carry!=0 && it==l.end()) l.push_back(carry);

    l.reverse();
    showlist(l);
}


int main()
{
    int n;
    cin>>n;
    list <int> li;
    int temp;
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        li.push_back(temp);   
    }

    //addition(li);
    multiplication(li);

}