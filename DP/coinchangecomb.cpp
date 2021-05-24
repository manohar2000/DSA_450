/*
1. You are given a number n, representing the count of coins.
2. You are given n numbers, representing the denominations of n coins.
3. You are given a number "amt".
4. You are required to calculate and print the number of combinations of the n coins using which the 
     amount "amt" can be paid.

Note1 -> You have an infinite supply of each coin denomination i.e. same coin denomination can be 
                  used for many installments in payment of "amt"
Note2 -> You are required to find the count of combinations and not permutations i.e.
                  2 + 2 + 3 = 7 and 2 + 3 + 2 = 7 and 3 + 2 + 2 = 7 are different permutations of same 
                  combination. You should treat them as 1 and not 3.

Sample Input
4
2 3 5 6
7
Sample Output
2
*/


#include<bits/stdc++.h>
using namespace std;

int combination(int denom[], int n, int amount)
{
    int dp[amount+1] = {};
    
    // ways of paying 0 is 0
    dp[0] = 1;
    
    
    for(int i=0;i<n;i++)
    {
        int den = denom[i];
        // ways of paying the jth amount using ith den
        for(int j=den;j<=amount;j++)
        {
            dp[j]+= dp[j-den];
        }
    }
    
    return dp[amount];
}


int main()
{
    int n;
    cin>>n;
    
    int den[n];
    
    for(int i=0;i<n;i++) cin>>den[i];
    
    int amount;
    cin>>amount;
    
    cout<<combination(den,n,amount)<<endl;
    
    
}