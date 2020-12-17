#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int a[1000][1000];

void rotate(int a[][1000], int m, int n)
{
    // LOGIC : to rotate the array anti-clockwise, reverse all the rows in the array and then transpose the array(arr[i][j]=arr[j][i])
    // to rotate the array clockwise, reverse all the columns and then do the transpose
    
    // reversing all the rows
    for(int i=0;i<n;i++)
    {
        int x=0;
        int y=n-1;
        while(x<y)
        {
            swap(a[x],a[y]);
            x++;
            y--;
        }
    }
    
    // transposing the array
    for(int i=0;i<n;i++)
    { 
        for(int j=0;j<i;j++)
        {
            swap(a[i][j],a[j][i]);
        }
    }
}


void rotate_stl(int a[][1000], int m, int n) //reversing the individual array using reverse stl
{
    
    for(int i=0;i<n;i++)
    {
       reverse(a[i],a[i]+n); 
    }
    
    // transposing the array
    for(int i=0;i<n;i++)
    { 
        for(int j=0;j<i;j++)
        {
            swap(a[i][j],a[j][i]);
        }
    }
}


void printArray(int a[][1000], int m, int n)
{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}


int main()
{
    int rows;
    int columns;
    
    cout<<"enter no. of rows:";
    cin>>rows;
    
    cout<<"enter no. of columns:";
    cin>>columns;
    
    // int a[rows][columns];
    int val = 1;
    cout<<"Actual array:"<<endl;
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<columns;j++)
        {
            a[i][j]=val;
            val+=1;
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<< "-----------" <<endl;
    cout<<"Rotated array:"<<endl;
    
    //rotate(a,rows,columns);
    
    rotate_stl(a,rows,columns);
    printArray(a,rows,columns);
    return 0;
}