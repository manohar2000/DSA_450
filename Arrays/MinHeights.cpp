/*
Given an array arr[] denoting heights of N towers and a positive integer K,
you have to modify the height of each tower either by increasing or decreasing them by K only once.
Find out what could be the possible minimum difference of the height of shortest and longest towers 
after you have modified each tower.

Input:
K = 2, N = 4
Arr[] = {1, 5, 8, 10}
Output:
5
Explanation:
The array can be modified as 
{3, 3, 6, 8}. The difference between 
the largest and the smallest is 8-3 = 5.
*/

using namespace std;
#include <bits/stdc++.h>

int getMinDiff(int arr[], int n, int k)
{
    sort(arr,arr+n);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    int ans = arr[n-1] - arr[0];
    for(int i=1;i<n;i++)
    {
        int small = min(arr[0]+k, arr[i]-k );
        int large = max(arr[n-1]-k, arr[i-1]+k);

        //if, after applying add/sub, negative height values are not allowed then:
        if(small<0) continue;

        ans = min(ans, large-small);
    }
    
    return ans;
}

int main()
{
    int k;
    cin>>k;
    int n;
    cin>>n;
    int arr[n] = {};
    for(int i=0;i<n;i++) cin>>arr[i];

    cout<<getMinDiff(arr, n,k);

}