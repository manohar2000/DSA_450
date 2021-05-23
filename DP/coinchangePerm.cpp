/*
1. You are given a number n, representing the count of coins.
2. You are given n numbers, representing the denominations of n coins.
3. You are given a number "amt".
4. You are required to calculate and print the number of permutations of the n coins using which the 
     amount "amt" can be paid.

Note1 -> You have an infinite supply of each coin denomination i.e. same coin denomination can be 
                  used for many installments in payment of "amt"
Note2 -> You are required to find the count of permutations and not combinations i.e.
                  2 + 2 + 3 = 7 and 2 + 3 + 2 = 7 and 3 + 2 + 2 = 7 are different permutations of same 
                  combination. You should treat them as 3 and not 1.


Sample Input
4
2 3 5 6
7
Sample Output
5
*/



#include<bits/stdc++.h>
using namespace std;

int permutations(int den[], int n, int amount)
{
  // dp array to store permutation to achieve each target
  // ith cell represents the total number of permutations possible to store the jth amount
  int dp[amount + 1] = {};

  // you can give nothing thus there is one way
  dp[0] = 1;

  // filling for each of the target
  for (int i = 1; i <= amount; i++)
  {
    // checking with each denomination
    for (int j = 0; j < n; j++)
    {
      int val = den[j];

      if (i < val) continue;

      else
      {
        dp[i] += dp[i - val];
      }
    }

  }

  return dp[amount];
}

int main()
{
  int n;
  cin >> n;

  int arr[n];

  for (int i = 0; i < n; i++) cin >> arr[i];

  int amount;
  cin >> amount;

  cout << permutations(arr, n, amount) << endl;

}

