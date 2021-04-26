/* Given an undirected graph with V vertices and E edges, 
check whether it contains any cycle or not using BFS
*/


class Solution {
public:
    bool isCycleUtil(int V,int s, vector<int>adj[], unordered_map<int,int> &visited)
    {
        vector<int> parent(V,-1);
        queue<int> q;
        visited[s] = true;
        q.push(s);
        
        while(!q.empty())
        {
            int temp = q.front();
            q.pop();
            
            for(auto i:adj[temp])
            {
                if(!visited[i])
                {
                    visited[i] = true;
                    q.push(i);
                    parent[i] = temp;
                }
                
                else if (parent[temp]!=i) return true;
                
            }
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
	            if(isCycleUtil(V,i,adj,visited)) return true;
	        }
	    }
	    
	    return false;
	    
	}
};