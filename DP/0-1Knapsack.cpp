/*
You are given weights and values of N items, put these items in a knapsack of capacity W to get 
the maximum total value in the knapsack. Note that we have only one quantity of each item.
In other words, given two integer arrays val[0..N-1] and wt[0..N-1] 
which represent values and weights associated with N items respectively. 
Also given an integer W which represents knapsack capacity, find out the maximum value subset of val[] 
such that sum of the weights of this subset is smaller than or equal to W. You cannot break an item, 
either pick the complete item, or don’t pick it (0-1 property).

Example 1:

Input:
N = 3
W = 4
values[] = {1,2,3}
weight[] = {4,5,1}
Output: 3
Example 2:

Input:
N = 3
W = 3
values[] = {1,2,3}
weight[] = {4,5,6}
Output: 0

*/


class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // dp array of size(n+1*W+1). 
       // Each state represents the maximum value that can be achieved till the given target
       int dp[n+1][W+1] = {0};
       
       // if we don't put any weights then value will be 0
       for(int i=0;i<=W;i++) dp[0][i] = 0;
       
       // if the capacity of bag is 0 then the value will be 0
       for(int i=0;i<=n;i++) dp[i][0] = 0;
       
       
       for(int i=1;i<=n;i++)
       {
           int weight = wt[i-1]; // weight of current item
           int value = val[i-1]; // value of current item 
           
           for(int j=1;j<=W;j++)
           {
               if(j<weight) dp[i][j] = dp[i-1][j]; // if weight of current item is greater than capacity of bag then we cannot include it
               
               // else we have two options
               // 1. either the current weight is ignored or,
               // 2. the current weight is included and the remaining value is filled by items before the current item
               else
               {
                   
                   if( (dp[i-1][j-weight] + value) > dp[i-1][j] )
                   {
                       dp[i][j] = dp[i-1][j-weight]+value;
                   }
                   
                   else dp[i][j] = dp[i-1][j];
               }
           }
       }
       
    //   for(int i=0;i<=W;i++) cout<<dp[2][i]<<" ";
    //   cout<<endl;
       
       
       return dp[n][W];
       
    }
};