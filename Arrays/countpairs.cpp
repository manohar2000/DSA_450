/*
Given an array of N integers, and an integer K, find the number of pairs of elements in the array
whose sum is equal to K.

Input:
N = 4, K = 6
arr[] = {1, 5, 7, 1}
Output: 2
Explanation: 
arr[0] + arr[1] = 1 + 5 = 6 
and arr[1] + arr[3] = 5 + 1 = 6.

Input:
N = 4, X = 2
arr[] = {1, 1, 1, 1}
Output: 6
Explanation: 
Each 1 will produce sum 2 with any 1.
*/


class Solution{   
public:
    int getPairsCount(int arr[], int n, int k)
    {
        // creatin freq array for the numbers in the array
        unordered_map<int, int> m;
        for(int i=0;i<n;i++) m[arr[i]]++;
        
        int count = 0;
        for(int i=0;i<n;i++)
        {
            count+= m[k-arr[i]];
            
            if(k-arr[i]==arr[i]) count--;
        }
        
        return count/2;
    }
};