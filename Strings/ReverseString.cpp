#include <bits/stdc++.h>
using namespace std;

void reverseString(vector<char>& s) 
{
    int n = s.size(); //size of the array
    
    for(int i=0,j=n-1; i<=n/2,j>=n/2;i++,j--)
    {            
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
    
    for(int i = 0;i<n;i++)
    {
        cout<<s[i]<<",";
    }
    
}

int main()
{
    vector<char> s = {'a','b','c','d'};
    reverseString(s);
}
