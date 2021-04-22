#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graph
{
    public:
        map<T, vector< pair<T,int> > > adjList;


        void addNode(T a, T b,int weight, bool bidirec=false)
        {
            adjList[a].push_back(make_pair(b,weight));
            if(bidirec) adjList[b].push_back(make_pair(a,weight));
        }


        void printNodes()
        {            
            for(auto node:adjList )
            {
                cout<<node.first<<"-->";

                // vector<pair<T,int>> :: iterator connectedNode;

                for(auto connectedNode: node.second)
                {
                    cout<<"{"<<connectedNode.first<<","<<connectedNode.second<<"}"<<",";
                }

                cout<<endl;
            }

        }
};


int main()
{

    Graph<int> g;

    g.addNode(1,2,10,true);
    g.addNode(1,3,12);
    g.addNode(2,4,14);
    g.addNode(3,2,16);
    g.addNode(3,4,18,true);

    g.printNodes();

    return 0;
}