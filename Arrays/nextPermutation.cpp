/*
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such an arrangement is not possible, it must rearrange it as the lowest possible order (i.e., sorted in ascending order).

The replacement must be in place and use only constant extra memory.
Input: nums = [1,2,3]
Output: [1,3,2]
Input: nums = [3,2,1]
Output: [1,2,3]

*/
#include <bits/stdc++.h>
using namespace std;


void reverse_arr(vector<int> &nums, int start, int end)
{
    while(start<=end)
    {
        swap(nums[start],nums[end]);
        start++;
        end--;
    }       
    
}

int nextGreater(vector<int> nums, int start, int end, int key)
{
    int j = 0;
    for(j=nums.size()-1;j>=start;j--)
    {
        if(nums[j]>key)
            break;           
    }
    
    return j;
    
}    


void nextPermutation(vector<int>& nums) 
{
    int i = nums.size()-2;
    
    // check where is the decreasing sequence is not following the order
    while(i>=0 && nums[i+1]<=nums[i]) 
    {
        i--;
    }
    
    
    if(i<0) reverse_arr(nums,i+1,nums.size()-1);
    
    else
    {                    
        // replace the digit with the next greatest digit in the number and swap these two
        int index = nextGreater(nums, i+1, nums.size()-1, nums[i]);
        swap(nums[i],nums[index]);

        // reverse the array from i+1 till end
        reverse_arr(nums,i+1,nums.size()-1);            
    }      
    
}

int main()
{
    vector<int> nums = {3,2,1};
    nextPermutation(nums);
    for(int i=0;i<nums.size();i++) cout<<nums[i]<<" ";
}