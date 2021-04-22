/*
Given two sorted arrays nums1 and nums2 of size m and n respectively,
return the median of the two sorted arrays.

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
*/

class Solution {
public:    
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)    
    {
        if(nums2.size()<nums1.size()) return findMedianSortedArrays(nums2,nums1);
        
        int start = 0;
        int end = nums1.size();
        
        while(start<=end)
        {
            
            int i1 = (start+end)/2;
            int i2 = ( nums1.size() + nums2.size() + 1)/2 - i1;

            int min1;
            if(i1==nums1.size()) min1 = INT_MAX;
            else min1 = nums1[i1];

            int max1;
            if(i1==0) max1 = INT_MIN;
            else max1 = nums1[i1-1];
            
            int min2;
            if(i2==nums2.size()) min2 = INT_MAX;
            else min2 = nums2[i2];            
            
            int max2;
            if(i2==0) max2 = INT_MIN;
            else max2 = nums2[i2-1];
            

            
            // cout<<min1<<" "<<max1<<" "<<min2<<" "<<max2<<endl;            
            
            if(max1<=min2 && max2<=min1)
            {
                if( (nums1.size()+nums2.size())%2==0)
                {
                  return (((double)(max(max1,max2) + min(min1,min2)))/2);  
                }                   
                
                return ( (double)(max(max1,max2)) );
            }
            
            else if(max1>min2) end = i1-1;  
            
            else start = i1+1;        
            
        } 
        
        return 1;
        
    }
};
