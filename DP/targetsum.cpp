#include<bits/stdc++.h>
using namespace std;

bool isExist(int arr[], int n, int target)
{
    bool dp[n+1][target+1];
    
    // dp[0][i] represent sum possible by empty set
    for(int i=0;i<=target;i++) dp[0][i] = false;
    
    // dp[i][0] represents sum of 0 possible with individual element.
    for(int i=0;i<=n;i++) dp[i][0] = true;
    
   
    dp[0][0] = true;
   
    // each cell represent that is there any subset in the till the arr[i-1]th elements that can form given the jth sum.
    
    // at every state, the arr[i-1]th element has an option to include itself or ask the previous elements if they can form the given target or not.
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=target;j++)
        {
            // if the selected target is less than arr[i-1]th element then it cannot be included and ans will solely depend on the previous elements.
            if(j<arr[i-1]) dp[i][j] = dp[i-1][j];
            
            // if arr[i-1]th element can be included then the cell will depend if the previous can make the given target or previous elements can produce the sum of target-arr[i-1] 
            else if(j>=arr[i-1])
                dp[i][j] = ( dp[i-1][j-arr[i-1]] or dp[i-1][j]);
        }
    }
    
    
    return dp[n][target];
    
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0 ; i < n ; i++) cin >> arr[i];
    
    int target;
    cin>>target;
    
    cout<<isExist(arr,n,target);
    
    return -1;
}
