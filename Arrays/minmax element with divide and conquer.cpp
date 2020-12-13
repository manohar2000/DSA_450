#include <iostream>
#include <stdio.h>
using namespace std;

// creating structure to store the min and max values
struct Pair
{
    int max;
    int min;
};

struct Pair getminmax(int arr[],int low,int high)
{
    struct Pair minimax,minimaxl,minimaxr;
    
    // if there is only 1 element in the array asign min and max to that element
    if(low==high)
    {
        minimax.min = arr[low];
        minimax.max = arr[low];
        
        return minimax;
    }
    // if there are 2 elements in the array, compare between them and assign the min and max
    if(high==low+1)
    {
        if(arr[low]>arr[high])
        {
            minimax.min = arr[high];
            minimax.max = arr[low];
        }
        else
        {
            minimax.min = arr[low];
            minimax.max = arr[high];
        }
        
    return minimax;
    }
    
    // for array having more than 2 elements
    // split the array into two halves recurisevly until we have either one element or two elements in the array
    int mid = (low+high)/2;
    minimaxl = getminmax(arr, low,mid);
    minimaxr = getminmax(arr, mid+1,high);
    
    //compare the min and max from left and right array and return the min and max element
    if(minimaxl.min>minimaxr.min)
    {
        minimax.min = minimaxr.min;
    }
    else minimax.min = minimaxl.min;
    
    if(minimaxl.max>minimaxr.max)
    {
        minimax.max = minimaxl.max ;
    }
    else minimax.max = minimaxr.max;
    
    return minimax;
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
  
  struct Pair minimax = getminmax(a,0,n-1);
  
  cout<<minimax.min <<" "<< minimax.max << endl;
  
}
