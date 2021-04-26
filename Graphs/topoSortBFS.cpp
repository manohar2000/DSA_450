// Given a Directed Graph with V vertices and E edges, Find any Topological Sorting of that Graph using BFS

class Solution{
	public:
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> ans;
	    
	    vector<int> incount(V,0);
	    
	    for(int i=0;i<V;i++)
	    {
	        for(auto j:adj[i]) incount[j]++;
	    }
	    
	    queue<int> q;
	    for(int i=0;i<V;i++)
	    {
	        if(incount[i]==0) q.push(i);
	    }
	    
	    while(!q.empty())
	    {
	        int node = q.front();
	        q.pop();
	        ans.push_back(node);
	        
	        for(auto childNode:adj[node])
	        {
	            if(--incount[childNode]==0) q.push(childNode);
	        }
	    }
	    
	    
	    return ans;
	}
};

