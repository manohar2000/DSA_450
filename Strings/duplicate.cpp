#include <bits/stdc++.h>
using namespace std;

//Write an efficient program to print all the duplicates and their counts in the input string 

void printDuplicates(string S)
{
    map<char, int> m;
    int size = S.size();
    for(int i=0;i<size;i++)
    {
        if(m[S[i]]==0)
        {
            m[S[i]] = 1;
        }
        else m[S[i]]+=1;
    }

    //printing all duplicate values with their count
    for(auto i : m)
    {
        if(i.second>1) cout<<i.first<<"="<<i.second<<endl;
    }

}



int main()
{
    string S = "test string";
    printDuplicates(S);
}