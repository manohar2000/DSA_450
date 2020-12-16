#include <stdio.h>
#include <iostream>
using namespace std;

int water_trapped(int arr[],int n)
{
    // Logic : Water filled at above a particular building will be equal to min(left,right) - current building height.
    // min(left,right) mean the minimum height amongst the tallest building to the left and tallest to the right of curr_building.

    int left[n];
    int right[n];

    left[0] = 0;
    right[n-1]=0;

    int left_max = arr[0];
    for(int i=1;i<n;i++)
    {
        if(arr[i]>left_max)
        {
            left_max = arr[i];            
        }
        left[i] = left_max;
    }

    int right_max = arr[n-1];
    for(int i=n-1;i>=0;i--)
    {
        if(arr[i]>right_max)
        {
            right_max = arr[i];
        }
        right[i] = right_max;
    }

    // calculating the water trapped
    int total = 0;
    for(int i=1;i<n-1;i++)
    {
        total+= min(left[i],right[i]) - arr[i];
    }

    return total;

}

int main() 
{
	int t;
	cin>>t;
	cin.get();
	
	for(int i=0;i<t;i++)
	{
	    int n;
	    cin>>n;
	    cin.get();
	    
	    int arr[100];
	    
	    for(int i=0;i<n;i++)
	    {
	        cin>>arr[i];
	    }

        cout<< water_trapped(arr,n) << endl;
	    
	}
	
	return 0;
}