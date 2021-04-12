/*
Given an array of integers. Find the Inversion Count in the array. 

Inversion Count: For an array, inversion count indicates how far (or close) the array
is from being sorted. If array is already sorted then the inversion count is 0.
 If an array is sorted in the reverse order then the inversion count is the maximum. 
Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.

Input: N = 5, arr[] = {2, 4, 1, 3, 5}
Output: 3
Explanation: The sequence 2, 4, 1, 3, 5 
has three inversions (2, 1), (4, 1), (4, 3).
*/

class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    
    long long int merge(long long arr[], long long temp[], long long int start, long long int mid, long long int end)
    {
      
      long long int i = start; // 0
      long long int k = start; //0
      long long int j = mid; // 1
      long long int inversion = 0;
      
      while(i<mid && j<=end)
      {
          if(arr[i]<=arr[j]) temp[k++] = arr[i++];
          
          else
          {
              temp[k++] = arr[j++];
              inversion+= mid - i;
              
          }
      }
      
      while(i<=mid-1) temp[k++] = arr[i++];
      
      while(j<=end) temp[k++] = arr[j++];
      
      for(i=start;i<=end;i++)
      {
          arr[i] = temp[i];
      }
      return inversion;
        
    }
    
    
    long long int mergeSort(long long arr[], long long temp[], long long int start, long long int end)
    {
        
        long long int inversions = 0;
        if(end>start)
        {
            long long int mid = (start+end)/2;
            
            inversions+= mergeSort(arr,temp,start, mid);
            inversions+= mergeSort(arr,temp,mid+1,end);
            inversions+= merge(arr,temp,start,mid+1,end);
            
        }
        
        return inversions;
    }
    
    
    long long int inversionCount(long long arr[], long long int N)
    {
        long long temp[N];
        return mergeSort(arr, temp, 0, N-1);
    }

};




