#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Graph
{
    public:
        map<T,vector<T>> adjList;

        void addnode(T a, T b, bool bidirec=false)
        {
            adjList[a].push_back(b);
            if(bidirec) adjList[b].push_back(a);
        }

        void printNodes()
        {
            for(auto node: adjList)
            {
                cout<<node.first<<"--->";
                for(auto connectedNode: node.second)
                {
                    cout<<connectedNode<<",";
                }
            }
        }


        void bfs(T node)
        {
            unordered_map<T,bool> visited;
            queue<T> q;

            q.push(node);
            visited[node] = true;

            while(!q.empty())
            {
                T temp = q.front();
                cout<<temp<<" ";
                q.pop();

                for(auto i:adjList[temp])
                {
                    if(visited[i]==false)
                    {
                        q.push(i);
                        visited[i] = true;
                    }
                }
            }
        }
};

int main()
{
    Graph<int> g;
    
    g.addnode(1,2,true);
    g.addnode(1,3);
    g.addnode(1,4);
    g.addnode(2,3);
    g.addnode(3,4,true);

    g.bfs(1);

}

