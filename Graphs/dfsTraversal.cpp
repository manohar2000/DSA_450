/*
Given a connected undirected graph. Perform a Depth First Traversal of the graph.
Note: Use recursive approach to find the DFS traversal of the graph starting 
from the 0th vertex from left to right according to the graph.
*/

class Solution {
public:
    vector<int> dfshelper(int V, vector<int> adj[], unordered_map<int, bool> &visited, vector<int> &ans)
    {
        visited[V] = true;
        ans.push_back(V);
        
        for(auto i:adj[V])
        {
            if(visited[i]==false)
            {
                dfshelper(i, adj, visited, ans);
            }
        }
        
        return ans;
        
    }
	vector<int>dfsOfGraph(int V, vector<int> adj[])
	{
	    unordered_map<int, bool> visited;
	    vector<int> ans;
	    ans = dfshelper(0, adj, visited, ans);
	    
	    return ans;
	}
};