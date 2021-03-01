/*
An array contains both positive and negative numbers in random order. 
Rearrange the array elements so that all negative numbers appear before all positive numbers.
*/
// Solution: The idea is same...two pointers in start and end and swap swap
using namespace std;
#include <bits/stdc++.h>


void sortNegPos(int arr[], int n)
{
    int i = 0;
    int j = n-1;
    while(i<=j)
    {
        if(arr[i]<=0) i++;
        
        else if(arr[i]>0)
        {
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
    }
}


int main()
{
    int n;
    cin>>n;
    int arr[n] = {};
    for(int i=0;i<n;i++) cin>>arr[i];

    sortNegPos(arr, n);

    for(int i=0;i<n;i++) cout<<arr[i]<<" ";

}