#include <stdio.h>
#include <iostream>
using namespace std;

// creating a pair for minmax 
struct Pair
{
    int min;
    int max;
};

// Logic : comparing the min and max with a pair of elements in the array 

struct Pair getminmax(int arr[], int n)
{
    struct Pair minmax;
    int i;
    
    // if there are odd no. of elements in the array then initializing the min and max with the first element
    if(n%2!=0)
    {
        minmax.min = arr[0];
        minmax.max = arr[0];
        i = 1; //we'll start making pairs from the second element element in the array
    }
    
    // if there the even no. of elements in the array then compring the first two elements and assigning them to min and max
    else
    {
       if(arr[0]>arr[1])
       {
           minmax.max = arr[0];
           minmax.min = arr[1];
       }
       else
       {
           minmax.min = arr[1];
           minmax.max = arr[0];
       }
       
       i= 2; //we'll start making pairs from the 3rd element in the array
    }
    
    //looping till the end of the array
    while(i<n-2)
    {
        if(arr[i]>arr[i+1])
        {
            if(arr[i]>minmax.max) minmax.max = arr[i];
            if(arr[i+1]<minmax.min) minmax.min = arr[i+1];
        }
        
        else if(arr[i]<arr[i+1])
        {
            if(arr[i+1]>minmax.max) minmax.max = arr[i+1];
            if(arr[i]<minmax.min) minmax.min = arr[i];
        }
        
        i+=2; //incrementing by two to make pairs
        

    }
    
    return minmax;
    
        
}


int main()
{
  int n;
  cout<<"enter the no. elements in the array"<<endl;
  cin>>n; //taking the number of elements in the array from the user

  int a[n]; //creating an array of n elements

  cout<<"enter the elements in the array"<<endl;
  // taking the input array from the user
  for(int i=0;i<n;i++)
  {
    cin>>a[i];
  }
  
  struct Pair minimax = getminmax(a,n);
  
  cout<<minimax.min <<" "<< minimax.max << endl;
  
  return 0;
  
}