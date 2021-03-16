/*
Given an array Arr that contains N integers (may be positive, negative or zero).
Find the product of the maximum product subarray.

Input:
N = 5
Arr[] = {6, -3, -10, 0, 2}
Output: 180
Explanation: Subarray with maximum product
is  6, -3, -10 which gives product as 180.

*/

class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(int *arr, int n)
	{
        long long minValue = arr[0];
        long long maxValue = arr[0];
        long long maxProduct = arr[0];
        
        for(int i=1;i<n;i++)
        {
            if(arr[i]<0) swap(minValue,maxValue);
            
            if(arr[i]*maxValue>arr[i]) maxValue = arr[i]*maxValue;
            else maxValue = arr[i];

            
            if(arr[i]*minValue<arr[i]) minValue = arr[i]*minValue;
            else minValue = arr[i];
            
            
            maxProduct = max(maxProduct, maxValue);
        }
        
        return maxProduct;
	    
	}
};