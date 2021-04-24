// Given a Directed Graph with V vertices and E edges, check whether it contains any cycle or not using BFS

class Solution {
public:
	bool isCyclic(int V, vector<int> adj[])
	{
        int incount[V] = {};
        
        for(int i=0;i<V;i++)
        {
            for(auto j:adj[i])
            {
                incount[j]+=1;
            }
        }
        
        queue<int> q;
        for(int k=0;k<V;k++)
        {
            if(incount[k]==0) q.push(k);
            
        }
        
        int count = 0;
        
        while(!q.empty())
        {
            int temp = q.front();
            q.pop();
            for(auto i:adj[temp])
            {
                if(--incount[i]==0) q.push(i);
                
            }
            
            
            count++;
        }
        
        
        if(count==V) return false;
        
        return true;
        
        
        
        
        
	}
};
