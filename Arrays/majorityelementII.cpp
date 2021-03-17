/*
Given an array of size n, find all elements in array that appear more than n/k times. 
For example, if the input arrays is {3, 1, 2, 2, 1, 2, 3, 3} and k is 4, 
then the output should be [2, 3]. Note that size of array is 8 (or n = 8), 
so we need to find all elements that appear more than 2 (or 8/4) times. 
There are two elements that appear more than two times, 2 and 3. 

*/

class Solution {
public:
    
    struct elearray
    {
        int element;
        int count;
    };
    
    
    vector<int> majorityElement(vector<int>& nums)
    {
        vector<int> v;
        
        int k = 3;
        int n = nums.size();
        elearray temp[k-1];
        
        for(int i=0;i<k-1;i++) temp[i].count = 0;
        
        
        for(int i=0;i<n;i++)
        {
            
            //if element is present in array then increase its count
            int j;
            for(j=0;j<k-1;j++)
            {
                if(temp[j].element==nums[i])
                {
                    temp[j].count+=1;
                    break;
                }
            }
            
            // if element is not present in the array, then we have two cases. 
            // 1. either there is an empty place in the temp array or
            // 2. the temp array is full
            

            if(j==(k-1))
            {
                int l;
                for(l=0;l<k-1;l++)
                {
                    if(temp[l].count==0)
                    {
                        temp[l].element = nums[i];
                        temp[l].count = 1;
                        break;
                    }
                }
                
                // 2. the temp array is full then we decrease the count of every element by 1
                if(l==k-1)
                {
                    for(l=0;l<k-1;l++)
                    {
                        temp[l].count-=1;
                    }  
                }
                
            }
            
                       
        }
        
        
        int count;
        // traversing through the temp array and checking if count is greater than n/k or not
        for(int i=0;i<k-1;i++)
        {
            count = 0;
            for(int x=0;x<n;x++)
            {
                if(temp[i].element==nums[x]) count++;
            }
            
            if(count> (n/k)) v.push_back(temp[i].element); 
            
        }
        
        return v;
        
        
    }
};