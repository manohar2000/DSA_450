/* Given an array A[] consisting 0s, 1s and 2s. The task is to write a function that sorts the given array.
The functions should put all 0s first, then all 1s and all 2s in last.
*/

// Solution is a variation of quick sort
using namespace std;
#include <bits/stdc++.h>

void sort012(int arr[], int n)
{
    int left = 0;
    int mid = 0;
    int right = n-1;

    // traverse through the array until right>mid.
    
    while(mid<=right)
    {    
        // If we encounter 0 then swap(left, mid) left++ and mid++
        if(arr[mid]==0)
        {
            swap(arr[left],arr[mid]);
            left++;
            mid++;
        }

        // if we encounter 1 mid++
        else if(arr[mid]==1) mid++;

        // if we encounter 2 the swap(mid, end) mid++ end--
        else if(arr[mid]==2)
        {
            swap(arr[mid],arr[right]);
            right--;
        }

    }
}


int main()
{
    int n;
    cin>>n;
    int arr[n] = {};
    for(int i=0;i<n;i++) cin>>arr[i];

    sort012(arr, n);

    for(int i=0;i<n;i++) cout<<arr[i]<<" ";

}