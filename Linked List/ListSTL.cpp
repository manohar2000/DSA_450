#include <bits/stdc++.h>
#include <list>
using namespace std;

int main()
{
    /*
    Useful functions in list STL:

    1) front() – Returns the value of the first element in the list.
    2) back() – Returns the value of the last element in the list .
    3) push_front(g) – Adds a new element ‘g’ at the beginning of the list .
    4) push_back(g) – Adds a new element ‘g’ at the end of the list.
    5) pop_front() – Removes the first element of the list, and reduces size of the list by 1.
    6) pop_back() – Removes the last element of the list, and reduces size of the list by 1.
    7) empty() – Returns whether the list is empty(1) or not(0).
    8) insert() – Inserts new elements in the list before the element at a specified position.
    9) erase() – Removes a single element or a range of elements from the list.
    10) assign() – Assigns new elements to list by replacing current elements and resizes the list.
    11) remove() – Removes all the elements from the list, which are equal to given element.
    12) reverse() – Reverses the list.
    13) size() – Returns the number of elements in the list.
    14) sort() – Sorts the list in increasing order.
    15) list::begin() and list::end() in C++ STL– begin() function returns an iterator pointing to the first element of the list.
    16) end()– end() function returns an iterator pointing to the theoretical last element which follows the last element.
    */

    list <int> l;

    //inserting in LL
    l.push_front(0);
    for(int i=1;i<=5;i++) l.push_back(i);

    cout<<"First element:"<<l.front()<<endl;
    cout<<"Last element:"<<l.back()<<endl;

    //Printing list
    list <int> :: iterator it;
    for(it = l.begin();it!=l.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;


    //Reversing LL
    cout<<"Reversed List"<<endl;    
    l.reverse();
    list <int> :: iterator it_reverse;
    for(it_reverse=l.begin(); it_reverse!=l.end();it_reverse++)
    {
        cout<<*it_reverse<<" ";
    }

    cout<<endl;


    // removing element
    l.pop_back();

    cout<<"Size of list before:"<<l.size()<<endl;
    while(!l.empty())
    {
        l.pop_front();
    }

    cout<<"Size of list after:"<<l.size()<<endl;

    return 0;
}