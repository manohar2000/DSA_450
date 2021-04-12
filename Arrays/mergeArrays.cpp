#include<bits/stdc++.h>
using namespace std;

//O(m*n) solutiom. 

class Solution{
public:
    void insertionSort(int arr[], int n)
    {
        int temp = arr[0];
        int i = 1;
        while(temp>=arr[i] && i<n)
        {
            arr[i-1] = arr[i];
            i++;
        }
        arr[i-1] = temp;
    }

    void printarr(int arr[],int n)
    {
        for(int i=0;i<n;i++) cout<<arr[i]<<" ";
        
        cout<<endl;
    }

	void merge(int arr1[], int arr2[], int n, int m) 
	{
	    for(int i=0;i<n;i++)
	    {
	        if(arr1[i]>arr2[0])
	        {
	            swap(arr1[i],arr2[0]);
	            insertionSort(arr2, m);
	        }
	    }
	}
};

// faster solution

class Solution{
public:
    int nextStep(int n)
    {
        if(n<=1) return 0;
        return (n/2) + (n%2);
    }
    
    void printArray(int arr[],int n)
    {
        for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    }
   
	void merge(int arr1[], int arr2[], int n, int m) 
	{
	    int step = nextStep(n+m);
	    
	    while(step>0)
	    {
            int i,j;
            

            for(i=0;i+step<n;i++)
            {
                if(arr1[i]>arr1[i+step]) 
                swap(arr1[i],arr1[i+step]);
            }
            
            //swapping in b/w 2 arrays
            if(step>n) j=step-n;
            else j=0;
            for(;i<n && j<m;i++,j++)
            {
                if(arr1[i]>arr2[j])
                swap(arr1[i],arr2[j]);
            }
            
            //swapping in the 2nd array
            if(j<m)
            {
                for(j=0;j+step<m;j++)
                {
                    if(arr2[j]>arr2[j+step])
                    swap(arr2[j],arr2[j+step]);
                }
            }
            
            step = nextStep(step);   
	    }
	    
	}