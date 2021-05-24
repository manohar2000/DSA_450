/*
Given a set of N items, each with a weight and a value, and a weight limit W. 
Find the maximum value of a collection containing any of the N items any number of times 
so that the total weight is less than or equal to W.

Example 1:

Input: N = 2, W = 3
val[] = {1, 1}
wt[] = {2, 1}
Output: 3
Explaination: Pick the 2nd element thrice.
 

Example 2:

Input: N = 4, W = 8
val[] = {1, 4, 5, 7}
wt[] = {1, 3, 4, 5}
Output: 11
Explaination: The optimal choice is to 
pick the 2nd and 4th element.
*/

class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        // 1d dp array of size w+1
        // each state represents max value that can be achieved using all the weights
        vector<int> dp(W+1,0);
        
        
        for(int i=1;i<=W;i++)
        {
            // for every target knapsack size we check with every weight
            for(int j=0;j<N;j++)
            {
                int weight = wt[j];
                int value = val[j];
                
                if(weight>i) continue;
                
                // if we include this weight and the remaining weight 
                // then we check we are able to achieve a higher value than the current value 
                else
                {
                    dp[i] = max(dp[i], dp[i-weight]+value);
                }
                
            }
        }
        
        return dp[W];
        
    }
};