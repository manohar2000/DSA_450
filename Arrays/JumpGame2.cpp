/*
Given an array of non-negative integers nums, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

You can assume that you can always reach the last index. 

Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. 
Jump 1 step from index 0 to 1, then 3 steps to the last index.
*/


// First Solution: This is an O(n**2) solution using dp

class Solution {
public:
    int jump(vector<int>& nums) 
    {
        int n = nums.size();
        int* dp = new int[n];
        int min;


        if(nums[0]==0 || n==0) return 0;

        dp[n-1] = 0;
        for(int i=(n-2);i>=0;i--)
        {
            if(nums[i]==0)
            {
                dp[i] = INT_MAX;
            }

            else if( nums[i]>= n-i-1 ) dp[i] = 1;

            else
            {
                min = INT_MAX ;
                for(int j = i + 1; j < n && j <= nums[i] + i; j++)
                {
                    if(min>dp[j]) min=dp[j];
                }

                if(min!=INT_MAX) dp[i]=min+1;
                else dp[i]=min;


            }
        }

        if(dp[0]==INT_MAX) return 0;
        else return dp[0];
        
               
        
    }
};


/* Fast Solution O(n) time and O(1) space
 The idea is to store info in 3 variables jump, steps and maxReach.
 The steps var is used to iterate through the array and eventually reach the end of the array. 
 The maxReach var keeps the value of the maxPossible distance we can cover from our current ith position
 Finally, the jump is our answer.
 Once the steps are exhausted i.e steps==0, it implies that we must have/should take a jump therefore we increase jump var
 To keep continiung in the array we update the steps var with maxSteps - i. 
 If we are not able to reach the curr indice. i.e we have exhausted our steps and our maxReach<=i then it means
 that we cannot move forward.
*/

class Solution {
public:
    int jump(vector<int>& nums) 
    {
        int n = nums.size();
        if(n==0 || nums[0]==0) return 0;

        else if(n<=1) return 0;

        int jumps = 1;
        int steps = nums[0];
        int maxReach = nums[0];

        for(int i=1;i<n;i++)
        {
            if(i == n-1) return jumps;

            steps--;
            maxReach = max(maxReach, nums[i]+i);

            if(steps==0)
            {
                jumps++;

                if(maxReach<=i) return -1;

                steps = maxReach - i;

            }
        }

        return 0;              
        
    }
};

