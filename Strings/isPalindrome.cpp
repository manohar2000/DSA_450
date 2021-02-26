#include <bits/stdc++.h>
using namespace std;


int isPlaindrome(string S)
{
    int palin = 1;
    int size = S.size();
    for(int i=0,j=size-1;i<=size/2,j>=size/2;i++,j--)
    {
        if(S[i]!=S[j])
        {
            palin = 0;
            break;
        }
    }
    return palin;
}


int main()
{
    string S = "abba";
    cout<<isPlaindrome(S);
}