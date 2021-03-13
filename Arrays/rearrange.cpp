/*
Given an array of positive and negative numbers, arrange them in an alternate fashion 
such that every positive number is followed by negative and vice-versa maintaining 
the order of appearance. Number of positive and negative numbers need not be equal.
If there are more positive numbers they appear at the end of the array.
If there are more negative numbers, they too appear in the end of the array.

Input:  arr[] = {1, 2, 3, -4, -1, 4}
Output: arr[] = {-4, 1, -1, 2, 3, 4}

Input:  arr[] = {-5, -2, 5, 2, 4, 7, 1, 8, 0, -8}
output: arr[] = {-5, 5, -2, 2, -8, 4, 7, 1, 8, 0}
*/
using namespace std;
#include <bits/stdc++.h>

void printArr(vector<int> v)
{
    for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
    cout<<endl;
}


void posnegSort(vector<int> v)
{
    //sorting the array such that all the neg elements are to the left and pos elements to the right
    int i = 0;
    int j = 0;

    while(j<v.size())
    {
        if(v[j]>0) j++;

        else
        {
            swap(v[i],v[j]);
            i++;
            j++;
        }        
    }

    if(i==0 || i==v.size()) return ;  // if all the elements are positive or negative

    // at this point i is at the first positive element.
    int k = 0;
    while (k < v.size() && i < v.size())
    {
        swap(v[k], v[i]);
        i = i + 1;
        k = k + 2;
    }

    printArr(v);

}


int main()
{
    int n;
    cin>>n;

    vector<int> v;

    int temp;
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        v.push_back(temp);
    }

    posnegSort(v);
}