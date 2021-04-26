/* Given an undirected graph with V vertices and E edges, 
check whether it contains any cycle or not using DFS
*/

class Solution {
public:
    bool isCycleUtil(int V, int parent, vector<int> adj[], unordered_map<int,int> &visited)
    {
        visited[V] = true;
        
        for(auto i:adj[V])
        {
            if(!visited[i])
            {
                if(isCycleUtil(i,V,adj,visited)) return true;
            }
            
            else if(i!=parent) return true;
        }
        
        return false;
        
    }


	bool isCycle(int V, vector<int>adj[])
	{
	    unordered_map<int, int> visited;
	    
	    for(int i=0;i<V;i++)
	    {
	        if(!visited[i])
	        {
	            if(isCycleUtil(i,-1,adj,visited)) return true;
	        }
	    }
	    
	    return false;
	    
	}
};