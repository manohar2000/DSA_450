#include <iostream>
#include <stdio.h>
using namespace std;

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

  // logic : start two indices, one from the start, other from the end and keep swapping
  
  for(int i=0,j=n-1;i<=n/2,j>=n/2;i++,j--)
  {
      int temp = a[i];
      a[i] = a[j];
      a[j] = temp;
  }

  cout<<"reversed array" << endl;
  for(int i=0;i<n;i++)
  {
    cout<<a[i]<<" ";
  }
  
  
}