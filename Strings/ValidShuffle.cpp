/*
We have to check if a string is the valid shuffle of two other strings.
1XY2 is a valid shuffle of XY and 12
Y12X is not a valid shuffle of XY and 12
*/
#include <bits/stdc++.h>
using namespace std;

bool validShuffle(string s1, string s2, string s3)
{
    int s1_size = s1.size();
    int s2_size = s2.size();
    int s3_size = s3.size();

    int i=0,j=0,k=0;
    
    while(k<s3_size)
    {


        // if both the strings have finished and there are some char remaining in s3 then return false
        if(i>s1_size && j>s2_size) return false;

        // if char of s3 matches with char of s1
        if(s3[k]==s1[i]) i++;

        // if char of s3 matches with char of s2
        else if(s3[k]==s2[j]) j++;

        // if it does not match with any, then simply return false
        else return false;

        k++;

    }

    // if there are some char remaining in s1 or s2 then return false
    if(i!=(s1_size) || j!=(s2_size) ) return false;

    return true;

}



int main()
{
    int s1_size;
    cin>>s1_size;
    string s1;
    char temp;
    for(int i=0;i<s1_size;i++)
    {
        cin>>temp;
        s1.push_back(temp);
    }    

    int s2_size;
    cin>>s2_size;
    string s2;
    for(int i=0;i<s2_size;i++)
    {
        cin>>temp;
        s2.push_back(temp);
    } 


    int s3_size;
    cin>>s3_size;
    string s3;
    for(int i=0;i<s3_size;i++)
    {
        cin>>temp;
        s3.push_back(temp);
    } 

    cout<<validShuffle(s1,s2,s3);

}
    

    