/*
Given an array of integers nums containing n + 1 integers where each integer 
is in the range [1, n] inclusive.
There is only one repeated number in nums, return this repeated number.
Input: nums = [1,3,4,2,2]
Output: 2
*/

class Solution {
public:
    /*
    This question can be done in O(n**2), sorting the array and 2ptr(O(nlog(n))),
    else we can keep a freq array.
    The freq array can be a hash map. But, since, we have been given that the elements
    will be from [0,n] only, we can use this to keep a count by creating a array of it.
    The most optimal solution is the floyd algorithm. Which is similar to
    finding a loop in a linked list   
    */
    
    
    int findDuplicate(vector<int>& nums)   
    {
        int slow = nums[0];
        int fast = nums[0];
        
        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(fast!=slow);
        
        // finding the entrance
        slow = nums[0];
        while(slow!=fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        
        return slow;       
        
        
    }
};