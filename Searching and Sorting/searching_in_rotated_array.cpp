#include <iostream>
using namespace std;

int search_in_rotated(int arr[],int key, int start, int end)
{
    /* Logic : The graph of this array will two linearly increasing lines with a break in between 
     e.g for an arra[4,5,6,1,2,3] the 1st line (1,4)-->(3,6) and 2nd line will be (4,1)--->(6,3) (1st co-oridnate is the indices)
    
    Now, the starting mid-point will either lie in the first line or the second.
    If the the mid-point lies in the first part then the sub-array from start to mid will be sorted--> 1st region  or, 
    If the mid-point lies in the second part then the sub-array from mid to end will be sorted--> 2nd region 

    And there will 3 places where the key can lie
    1. arr[start]<=key<=arr[mid] i.e the 1st region
    2. arr[mid]<=arr[end] i.e the 2nd region
    3. somewhere in the middle  mid+1-->end or start-->mid-1
    */

   if(start>end) 
   {
       return -1;
   }

   int mid = (start+end)/2;

   if(arr[mid]==key)
   { 
       return mid;
   }

    // first line
   if(arr[start]<=arr[mid])
   {
       if(key>=arr[start] && key<=arr[mid]) // 1st region
       {
           return search_in_rotated(arr,key,start,mid-1);
       }
       else
       {
           return search_in_rotated(arr,key,mid+1,end); //middle region
       }      
   }

   else
   {
       if(key>=arr[mid] && key<=arr[end])
       {
            return search_in_rotated(arr,key,mid+1,end);  // 2nd region
       }      
   }  
   return search_in_rotated(arr,key,start,mid-1);

}

int main()
{
    int n;
    cin>>n;
    cin.get();

    int key;
    cin>>key;

    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    cout<<search_in_rotated(arr,key,0,n-1);

    return 0;
}