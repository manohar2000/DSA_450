#include<bits/stdc++.h>
using namespace std;

template <typename T>
class Graph
{
    public:
    // unordered map of vertices and connected edges with their corresponsding weights
    unordered_map<T, vector<pair<T,int>>> adjList;

    void addEdge(T a, T b, int weight, bool bidirec=true)
    {
        adjList[a].push_back(make_pair(b,weight));
        if(bidirec)
        {
            adjList[b].push_back(make_pair(a,weight));
        }
    }



    void dijkstraSSP(T source)
    {
        unordered_map<T, int> dist;
        for(auto i:adjList)
        {
            dist[i.first] = INT_MAX;
        }

        dist[source] = 0;

        set<pair<int, T>> s;

        s.insert(make_pair(0,source));

        while(!s.empty())
        {
            auto p = *(s.begin());
            s.erase(s.begin());

            T node = p.second;
            int node_dist = p.first;

            for(auto i: adjList[node])
            {
                if( node_dist+i.second < dist[i.first])
                {
                    auto f = s.find(make_pair(dist[i.first] ,i.first));
                    if(f!=s.end())
                    {
                        s.erase(f);
                    }

                    dist[i.first] = node_dist + i.second;
                    s.insert(make_pair(node_dist+i.second, i.first));
                }

            }
        }

        for(auto i:dist)
        {
            cout<<i.first<<" "<<i.second<<endl;
        }

    }

};

int main()
{

    Graph<int> g;
    g.addEdge(1,2,1);
    g.addEdge(1,3,4);
    g.addEdge(2,3,1);
    g.addEdge(3,4,2);
    g.addEdge(1,4,7);
    g.dijkstraSSP(1);

}




