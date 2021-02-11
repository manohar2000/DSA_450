// Given an array of n elements, where each element is at most k away from its target position, 
// you need to sort the array optimally.

#include <bits/stdc++.h>
using namespace std;


vector <int> nearlySorted(int arr[], int num, int K){
    priority_queue<int, vector<int>, greater<int> > pq;
    
    vector<int> v;
    
    int i = 0;
    while(i<K+1 && i<num)
    {
        pq.push(arr[i]);
        i++;
    }
    
    while(i<num)
    {
        v.push_back(pq.top());
        pq.pop();
        pq.push(arr[i]);
        i++;
    }
    
    while(!pq.empty())
    {
        v.push_back(pq.top());
        pq.pop();
    }
    
    return v;

}

void printArray(vector<int> arr, int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
  
int main()
{
    int k = 3;
    int arr[]= { 2, 6, 3, 12, 56, 8 };
    int n = sizeof(arr) / sizeof(arr[0]);


    vector<int> sorted_arr = nearlySorted(arr, n, k);
  
    cout << "Following is sorted array" << endl;
    printArray(sorted_arr, n);
  
    return 0;
}