class Solution{
    public:
    // arr: input array
    // num: size of array
    //Function to find maximum circular subarray sum.
    
    int kadaneSum(int arr[], int n)
    {
        int max_sum = 0;
        int curr_sum = 0;
        
        for(int i=0;i<n;i++)
        {
            curr_sum+= arr[i];
            
            if(curr_sum>max_sum) max_sum = curr_sum;
            
            if(curr_sum<0) curr_sum = 0;
        }
        

        return max_sum;
    }
    
    
    int circularSubarraySum(int arr[], int num)
    {
        // this method does not work if all elements are negative, therefore we have to 
        // check if all no's are negative or not. If all are negative then return the max of -ves
        bool flag = true;
        int maxele = INT_MIN;
        for(int i=0;i<num;i++)
        {
            if(arr[i]>=0) 
            {
                flag = false;
                break;
            }
            
            else if(arr[i]>maxele) maxele = arr[i];
        }
        
        if(flag==true) return maxele;
        

        int noWrapSum;
        // kadane's sum
        
        noWrapSum = kadaneSum(arr, num);
        
        if(noWrapSum < 0) return noWrapSum;
        

        // wrap around sum-max sum including corner elements
        // i.e sumofarray - (- min sum subrray) or sumofarray + (max subarray of inverted array)
        int wrapSum = arr[0];
        arr[0] = -arr[0];
        for(int i=1;i<num;i++)
        {
            wrapSum+=arr[i];
            arr[i] = -arr[i];
        }
        
        wrapSum = wrapSum + kadaneSum(arr,num);

        
        //ans = max(kadane's sum, wrap around sum)
        return max(noWrapSum, wrapSum);
    }
};