/*
Given an array of size n and a range [a, b]. The task is to partition the array around the range such that array is divided into three parts.
1) All elements smaller than a come first.
2) All elements in range a to b come next.
3) All elements greater than b appear in the end.
The individual elements of three sets can appear in any order. You are required to return the modified array.


Example 1:

Input: 
n = 5
A[] = {1, 2, 3, 3, 4}
[a, b] = [1, 2]
Output: 1
Explanation: One possible arrangement is:
{1, 2, 3, 3, 4}. If you return a valid
arrangement, output will be 1.


Solution: Dutch National Flag algorithm
*/


class Solution{   
public:
    //Function to partition the array around the range such 
    //that array is divided into three parts.
    
    void printarr(vector<int> array)
    {
        for(int i=0;i<array.size();i++) cout<<array[i]<<" ";
        cout<<endl;
    }
    
    void threeWayPartition(vector<int>& array,int a, int b)
    {
        int i = 0;
        int j = array.size()-1;
        int k = 0;

        while(k<=j)
        {
            
            if(array[k]<a)
            {
                swap(array[i++],array[k++]);
            }
            
            else if(array[k]>b)
            {
                swap(array[j--],array[k]);
            }
            
            else k++;
            
        }
    }
};