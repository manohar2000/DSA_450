#include <iostream>
#include <cstring>
using namespace std;

int a[1000][1000];

void spiralprint(int a[][1000], int m, int n)
{
    // LOGIC : Take 4 pointers at the 4 corners of the matrix to print the top row, rightmost row, bottom row and leftmost row consecutively
    // increment startRow and startColumn to move inside the matrix
    // decrment endRow and endColumn to move inside the matrix

    int startCol = 0;
    int endCol = n-1;
    int startRow = 0;
    int endRow = m-1;
    
    while(startCol<=endCol && startRow<=endRow)
    {
        // printing the topmost row
        for(int i=startCol;i<=endCol;i++)
        {
            cout<<a[startRow][i]<<" ";
        }
        startRow++; 
        
        // printing the rightmost row
        for(int i=startRow;i<=endRow;i++)
        {
            cout<<a[i][endCol]<<" ";
        }
        endCol--;
        
        // printing the bottom most row
        if(endRow > startRow) // to avoid printing repition of element of error in case of array size like 3*5
        {
            for(int i=endCol;i>=startCol;i--)
            {
                cout<<a[endRow][i]<<" ";
            }
            endRow--;
        }
        
        // printing the left most row
        if(endCol>startCol) // to avoid printing repition of element of error in case of array size like 3*5
        {
            for(int i=endRow;i>=startRow;i--)
            {
                cout<<a[i][startCol]<<" ";
            }        
        startCol++;
        }
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
    spiralprint(a,rows,columns);
    return 0;
}