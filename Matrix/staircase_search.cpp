#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int a[1000][1000];

void search(int a[][1000], int m, int n, int k)
{
    int i = 0;
    int j = m-1;
    
    
    
    while(a[i][j]!=k)
    {
        
        if(a[i][j]>k)
        {
            j-=1;
        }
        if(a[i][j]<k)
        {
            i+=1;
        }
    }
    
    cout<<"answer:"<<"("<<i<<","<<j<<")"<<endl;
}


int main()
{
    int rows;
    int columns;
    int k;
    
    cout<<"enter no. of rows:";
    cin>>rows;
    
    cout<<"enter no. of columns:";
    cin>>columns;
    
    cout<<"enter the array elements:"<<endl;
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<columns;j++)
        {
            cin>>a[i][j];
        }
    }
    
    cout<<"enter element to be searched"<<endl;
    cin>>k;
    cout<<endl;
    search(a,rows,columns,k);
    return 0;
}