/* Given a Directed Graph with V vertices and E edges,
Find the number of strongly connected components in the graph.
*/

class Solution{
	public:
	/*  Function to find the number of strongly connected components
    *   using Kosaraju's algorithm
    *   V: number of vertices
    *   adj[]: array of vectors to represent graph
    */
    void fillOrder(int node,vector<int> adj[],vector<int> &order,vector<bool> &visited )
    {
        visited[node] = true;
        for(auto i:adj[node])
        {
            if(!visited[i]) fillOrder(i,adj,order,visited);
        }
        order.push_back(node);
    }
    
    void dfs(int node, vector<int> rev[], vector<bool> &rvisited)
    {
        
        rvisited[node] = true;
        for(auto i:rev[node])
        {
            if(!rvisited[i]) dfs(i,rev,rvisited);
        }
    }
    
    int kosaraju(int V, vector<int> adj[]) 
    {
        
        vector<int> rev[V];
        
        //reversing the graph
        for(int y=0;y<V;y++)
        {
            for(auto x:adj[y]) rev[x].push_back(y);
        }
        
        // for(int i=0;i<V;i++)
        // {
        //     cout<<i<<"-->";
        //     for(auto j:rev[i]) cout<<j<<",";
        //     cout<<endl;
        // }
        
        
        vector<bool> visited(V,false);
        vector<int> order;
        
        //creating an order 
        for(int i=0;i<V;i++)
        {
            if(!visited[i]) fillOrder(i,adj,order,visited);
        }
        
        // for(int i=0;i<V;i++) cout<<order[i]<<" ";
        // cout<<endl;
        
        // counting the strongly connected edges
        int count = 0;
        vector<bool> rvisited(V,false);

        
        for(int i=V-1;i>=0;i--)
        {
            if(!rvisited[order[i]])
            {
                dfs(order[i],rev,rvisited);
                count++;
            }
            
        }
        
        return count;
    }
};
