#include <bits/stdc++.h>
using namespace std;

void color(unordered_map<int,vector<int>> adjList, int V)
{


    int nodeColor[V];
    for(int i=0;i<V;i++) nodeColor[i] = -1;

    bool colorAvail[V];
    for(int i=0;i<V;i++) colorAvail[i] = true;

    nodeColor[0] = 0;
    int maxColor = 0;

    for(int i=1;i<V;i++)
    {
      
        for(auto child:adjList[i])
        {
            
            if(nodeColor[child]!=-1) colorAvail[nodeColor[child]] = false;
        }

        
        
        int cn;
        for(cn=0;i<V;cn++)
        {
      
            if(colorAvail[cn]==1) break;
        }        

        maxColor = max(maxColor, cn+1);

        nodeColor[i] = cn;

        for(auto child:adjList[i])
        {
            if(nodeColor[child]!=-1) colorAvail[nodeColor[child]] = true;
        }
    }

    cout<<maxColor<<endl;
    for(int i=0;i<V;i++) cout<<i<<":"<<nodeColor[i]<<endl;
}



int main()
{
    int V;
    int edges;   

    cin>>V>>edges;

    unordered_map<int,vector<int>> adjList;

    for(int i=0;i<edges;i++)
    {
        int a,b;
        cin>>a>>b;

        adjList[a].push_back(b);
        adjList[b].push_back(a);

    }

    color(adjList, V);

    return 0;
}