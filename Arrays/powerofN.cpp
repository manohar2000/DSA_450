// Implement pow(x, n), which calculates x raised to the power n (i.e. xn).
// Input: 1) x = 2.00000, n = 10 Output: 1024.00000 ..... 2) Input: x = 2.00000, n = -2 Output: 0.25000

class Solution {
public:
    double myPow(double x, long int n)
    {
        if(n==0) return 1;
        
        else if(n<0) return 1/myPow(x,-n);
        
        else
        {
            double res = 1;
            while(n>0)
            {
                if(n&1) res*=x;
                
                x*=x;
                n = n>>1;
                
            }
            
            return res;
        }
    }
};

