/*
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, 
and return an array of the non-overlapping intervals that cover all the intervals in the input.

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].

Input: [[1,4],[2,3]]
Output:  [[1,4]]
*/

class Solution {
public:    
    
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        //output array
        int n = intervals.size();
        
        if(n<=1) return intervals;        
        
        vector<vector<int>> ans;
        
        sort(intervals.begin(), intervals.end());        
        
        int index = 0;  
        ans.push_back(intervals[0]);
        
        for(int i=1;i<n;i++)
        {
                        
            if(intervals[i][0]> ans[index][1])
            {
                ans.push_back(intervals[i]);
                index++;
            }
            
            
            else
            {
                if(ans[index][1]<intervals[i][1])
                    ans[index][1] = intervals[i][1];       
                
            }
            
        }   
        
        return ans;
    }
};