/*
Given an array of integers (A[])  and a number x, find the smallest subarray with sum greater than the given value.

Note: The answer always exists. It is guaranteed that x doesn't exceed the summation of a[i] (from 1 to N).

Example 1:

Input:
A[] = {1, 4, 45, 6, 0, 19}
x  =  51
Output: 3
Explanation:
Minimum length subarray is 
{4, 45, 6}

Example 2:
Input:
A[] = {1, 10, 5, 2, 7}
   x  = 9
Output: 1
Explanation:
Minimum length subarray is {10}
*/

class Solution{
  public:

    int sb(int arr[], int n, int x)
    {
        int i = 0;
        int j = 1;
        int min_len = n;
        int temp_sum = arr[0];

        while(j<n)
        {
            temp_sum+= arr[j];
            if(temp_sum>x) min_len = min(min_len, j-i+1);
            
            while(temp_sum>x)
            {
                temp_sum-=arr[i];
                i++;
                
                if(temp_sum>x) min_len = min(min_len, j-i+1);
            }
            
            j++;
            
        }
        return min_len;
    }
};



