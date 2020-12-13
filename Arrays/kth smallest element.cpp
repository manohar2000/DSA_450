#include <stdio.h>
#include <iostream>
using namespace std;
#include <algorithm>

int kmin(int arr[],int n,int k)
{
    sort(arr,arr+n);
    return arr[k-1];
}

int main()
{
  int n,k;
  cout<<"enter the no. elements in the array"<<endl;
  cin>>n; //taking the number of elements in the array from the user

  int a[n]; //creating an array of n elements

  cout<<"enter the elements in the array"<<endl;
  // taking the input array from the user
  for(int i=0;i<n;i++)
  {
    cin>>a[i];
  }
  cout<<"enter value of k"<<endl;
  cin>>k;
  
  int min = kmin(a,n,k);
  
  cout<<"the kth smallest element is:"<< min << endl;
  
  return 0;
  
}