

#include<bits/stdc++.h>
using namespace std;

int dist[10][10] = {{0,20,42,25},
                    {20,0,30,34},
                    {42,30,0,10},
                    {25,34,10,0}};

int n = 4;
int visited_all = (1<<n) - 1;

int dp[16][4];

int tsp(int mask, int city)
{
    if(mask==visited_all) return dist[city][0];

    int ans = INT_MAX;

    if(dp[mask][city]!=-1) return dp[mask][city];

    for(int i=0;i<n;i++)
    {
        // if we haven't visited the curr city
        if( (mask&(1<<i))==0) 
        {        
            // the mask of next city is always curr_mask || (1<<city no we want to go)
            // e.g we are at 1 city and want to explore the 3rd city. the curr_mask = 0001 
            // and next mask will 0001 || 0100 which gives us 0101
            int cost = dist[city][i] + tsp( mask|(1<<i),i);
            ans = min(ans,cost);
        }
    }
    return ans;
}

int main()
{
    for(int i=0;i<(1<<n);i++)
    {
        for(int j=0;j<n;j++) dp[i][j] = -1;
    }

    cout<<tsp(1,0)<<endl;


    return 0;
}


