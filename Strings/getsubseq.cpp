/*
1. You are given a string str.
2. Complete the body of getSS function - without changing signature - to calculate all subsequences of str.
Use sample input and output to take idea about subsequences.
*/

#include <iostream>
#include <vector>
using namespace std;

vector<string> gss(string s)
{
    if(s.length()==0)
    {
        vector<string> res(1,"");
        return res;
        
    }
    
    char first = s[0];
    string rest = s.substr(1);
    
    vector<string> rres = gss(rest);
    
    vector<string> result;
    
    for(int i=0;i<rres.size();i++)
    {
        result.push_back(""+ rres[i]);
        
    }
    
    for(int i=0;i<rres.size();i++)
    {
        result.push_back(first+ rres[i]);
    }
    
    return result;
    
}

int main(){
    string s;
    cin >> s;
    vector<string> ans = gss(s);
    int cnt = 0;

    cout << '[';
    for (string str : ans){
        if (cnt != ans.size() - 1)
            cout << str << ", ";
        else
            cout << str;
        cnt++;
    }
    cout << ']';
}