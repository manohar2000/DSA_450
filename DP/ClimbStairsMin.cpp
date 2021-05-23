/*
1. You are given a number n, representing the number of stairs in a staircase.
2. You are on the 0th step and are required to climb to the top.
3. You are given n numbers, where ith element's value represents - till how far from the step you 
     could jump to in a single move.  You can of-course fewer number of steps in the move.
4. You are required to print the number of minimum moves in which you can reach the top of 
     staircase.
Note -> If there is no path through the staircase print null.

Sample Input
10
3 3 0 2 1 2 4 2 0 0
Sample Output
4
*/

#include <iostream>
using namespace std;

void helper(int arr[], int pos, int n, int &count)
{
    if(pos>=n)
    {
        count++;
        return;
    }
    
    for(int i=pos; i<pos+arr[pos] && i<n;i++)
    {
        helper(arr,pos+i,n,count);
    }
    
}


int cs(int arr[], int n)
{
    int pos = 0;
    int count = 0;
    helper(arr,pos,n,count);
  
    return count;

  return 0;
}

int main() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0 ; i < n ; i++) {
    cin >> arr[i];
  }
  cout << cs(arr, n) << endl;
}