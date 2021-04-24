// Given a Directed Graph with V vertices and E edges, check whether it contains any cycle or not.


class Solution {
public:
    
    bool isCyclicHelper(int node,  vector<int> adj[], unordered_map<int,bool> &visited, unordered_map<int,bool> &instack)
    {
        if(visited[node]==false)
        {
            visited[node] = true;
            instack[node] = true;
            
            for(auto i:adj[node])
            {
                if(!visited[i] && isCyclicHelper(i, adj, visited, instack)) return true;
                
                else if(instack[i]==true) return true;
            }
            
        }
        
        instack[node] = false;
        return false;
    }


	bool isCyclic(int V, vector<int> adj[])
	{
	    unordered_map<int, bool> visited;
	    unordered_map<int, bool> instack;
	    
	    for(int i=0;i<V;i++)
	    {
	        if(isCyclicHelper(i, adj, visited, instack)) return true;
	        
	    }
	    
	    return false;
        
        
	}