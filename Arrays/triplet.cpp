/*
Given an array arr of size N and an integer X. Find if there's a triplet in the array 
which sums up to the given integer X.

Input:
N = 6, X = 13
arr[] = [1 4 45 6 10 8]
Output:
1
Explanation:
The triplet {1, 4, 8} in 
the array sums up to 13.
*/

class Solution
{
    public:
    
    // arr[] : The input Array
    // N : Size of the Array
    // X : Sum which you need to search for 
    //Function to find if there exists a triplet in the 
    //array arr[] which sums up to X.
    bool find3Numbers(int arr[], int N, int X)
    {
        sort(arr, arr+N);
        int temp;
        int i,j;
        
        for(int x=0;x<N;x++)
        {
            temp = X - arr[x];
            i = x+1;
            j = N-1;
            while(i<j)
            {
                if(arr[i]+arr[j]==temp) return true;
                
                else if(arr[i]+arr[j]<temp) i++;
                
                else if(arr[i]+arr[j]>temp) j--;
            }
        }
        
        return false;
        
    }
    

};