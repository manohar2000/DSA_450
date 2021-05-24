/*
Given weights and values of N items, we need to put these items in a knapsack of capacity W 
to get the maximum total value in the knapsack.
Note: Unlike 0/1 knapsack, you are allowed to break the item. 

Example 1:

Input:
N = 3, W = 50
values[] = {60,100,120}
weight[] = {10,20,30}
Output:
240.00
Explanation:Total maximum value of item
we can have is 240.00 from the given
capacity of sack. 
Example 2:

Input:
N = 2, W = 50
values[] = {60,100}
weight[] = {10,20}
Output:
160.00
Explanation:
Total maximum value of item
we can have is 160.00 from the given
capacity of sack.

*/


class Solution
{
    public:
    // custom sort pair.first = value pair.second = weight
    // sorting based on value/weight 
    static bool custom_sort(Item a, Item b)
    {
        double ratio1 = (double)a.value/(double)a.weight;
        double ratio2 = (double)b.value/(double)b.weight;
        
        return ratio1>ratio2;
    }
    
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // solving by greedy approach
        
        // sorting based on wieght/value ratio
        sort(arr,arr+n,custom_sort);
        

        double maxval = 0;
        for(int i=0;i<n && W>0 ;i++)
        {
            // taking the whole item since it's ratio is greater
           if(W>=arr[i].weight)
           {
               W-=arr[i].weight;
               maxval+=arr[i].value;
           }
           
           // else if weight is less then taking a part of the item
           else
           {
               maxval+=(W)*((double)arr[i].value/(double)arr[i].weight);
               break;
           }
            
        }
        
        
        return maxval;
        
    }
        
};