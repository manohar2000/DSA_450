#include <iostream>
#include <cstring>
using namespace std;

int a[1000][1000];

void spiralprint(int matrix[][1000], int r, int c)
{
    // LOGIC : Take 4 pointers at the 4 corners of the matrix to print the top row, rightmost row, bottom row and leftmost row consecutively
    // increment startRow and startColumn to move inside the matrix
    // decrment endRow and endColumn to move inside the matrix

    int left = 0;
    int top = 0;
    
    
    while(left<c && top<r)
    {
        // top row
        for(int i=left;i<c;i++)
        {
            cout<<(matrix[top][i]);
        }
        top++;
        
        // right row
        for(int i=top;i<r;i++)
        {
            cout<<(matrix[i][c-1]);
        }
        c--;
        
        
        //bottom row
        if(top<r)
        {
            for(int i=(c-1);i>=left;i--)
            {
                cout<<(matrix[r-1][i]);
            }
            r--;
        }
        
        // left row
        if(left<c)
        {
            for(int i=(r-1);i>=top;i--)
            {
                cout<<(matrix[i][left]);
            }
            left++;
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