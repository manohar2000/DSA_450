/*
Given an large integer N, find its factorial.

Input: N = 10
Output: 3628800
Explanation :
10! = 1*2*3*4*5*6*7*8*9*10 = 3628800

Solution: Use an array of integers to store the digits
*/


class Solution
{
    public:
    
    vector<int> multiply(vector<int> res, int n)
    {
        int carry = 0;
        int product = 1;
        
        int res_size = res.size();
        
        for(int i=0;i<res_size;i++)
        {
            product = res[i]*n + carry;
            res[i] = product%10;
            carry = product/10;
        }
        
        while(carry!=0)
        {
            res.push_back(carry%10);
            carry/=10;
            res_size+=1;
        }

        return res;   
    }
    
    
    vector<int> factorial(int N)
    {
        vector<int> res;
        int res_size = 1;
        res.push_back(1);
        
        for(int i=2;i<=N;i++)
        {
            res = multiply(res,i);
        }
        
        
        // return the reversed vector
        int i = 0;
        int j = res.size()-1;
        while(i<=j)
        {
            swap(res[i],res[j]);
            i++;
            j--;
        }
        
        return res;
        
    }