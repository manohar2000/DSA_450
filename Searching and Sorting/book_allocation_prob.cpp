#include <iostream>
using namespace std;

bool isValidConfig(int arr[], int n, int k, int ans)
{
    int students = 1;
    int current_pages = 0;

    for(int i=0;i<n;i++)
    {
        if(current_pages+arr[i]>ans)
        {
            current_pages = arr[i];
            students++;
            if(students>k) return false;
        }

        else
        {
            current_pages+=arr[i];
        }
        
    }
    return true;
}

int max_pages(int arr[], int m, int n)
{
    int total_pages = 0;
    int s = 0;
    int e = 0;
    for(int i=0;i<m;i++)
    {
        total_pages+=arr[i];
        s = max(s,arr[i]);
    }
    e = total_pages;
    int finalAns = 0;

    while(s<=e)
    {
        int mid = (s+e)/2;

        if(isValidConfig(arr,m,n,mid))
        {
            //true
            finalAns = mid;
            e = mid -1 ;
        }
        else
        {
            s = mid+1;
        }
        
    }
    return finalAns;

}

int main()
{
    int m,n; // no. of books and students respectively
    cin>>m>>n;
    cin.get();

    int arr[m];

    for(int i=0;i<m;i++)
    {
        cin>>arr[i];        
    }



    cout << max_pages(arr,m,n);


}