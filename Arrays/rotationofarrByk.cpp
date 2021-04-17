/* Given an array, rotate the array to the right by k steps, where k is non-negative.
Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]


Solution: Cyclic rotation in sets. Refer: https://www.geeksforgeeks.org/array-rotation/
optimal and counter-intuitve approach
*/
class Solution {
public:
    int gcd(int a, int b)
    {
        if(b==0) return a;
        
        else return gcd(b,a%b);
    }   
    
    
    void rotate(vector<int>& nums, int k) 
    {
        int n = nums.size();
        k = k%n;
        k = n-k; // for rotating the array to the right
        int g_c_d = gcd(n,k);
        for(int i=0;i<g_c_d;i++)
        {
            int temp = nums[i];
            int j = i;
            
            while(1)
            {
                int d = j+k;
                
                if(d>=n) d = d-n;
                
                if(d==i) break;
                
                
                nums[j] = nums[d];
                j = d;               
                
            }
            
            nums[j] = temp;           
            
        }      
        
    }
};