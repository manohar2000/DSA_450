/*
Given a sorted dictionary of an alien language having N words and k starting alphabets of standard dictionary. 
Find the order of characters in the alien language.
Note: Many orders may be possible for a particular test case, thus you may return any valid order 
and output will be 1 if the order of string returned by the function is correct 
else 0 denoting incorrect string returned.

Input: 
N = 5, K = 4
dict = {"baa","abcd","abca","cab","cad"}
Output:
1
Explanation:
Here order of characters is 
'b', 'd', 'a', 'c' Note that words are sorted 
and in the given language "baa" comes before 
"abcd", therefore 'b' is before 'a' in output.
Similarly we can find other orders.
*/


class Solution
{
    public:
    
    void toposort(int node, unordered_map<int,vector<int>> &adjList, vector<bool> &visited, string &ans)
    {
        visited[node] = 1;
        
        for(auto i:adjList[node])
        {
            if(!visited[i]) toposort(i,adjList,visited,ans);
        }
        
        ans = (char)(node+'a') + ans;
    }
    
    
    string findOrder(string dict[], int N, int K) 
    {
        unordered_map<int, vector<int> > adjList;
        
        for(int i=0;i<N-1;i++)
        {
            string word1 = dict[i];
            string word2 = dict[i+1];
            
            for(int j=0;j<min(word1.length(),word2.length());j++)
            {
                if(word1[j]!=word2[j])
                {
                    
                    adjList[word1[j]-'a'].push_back(word2[j]-'a');
                    break;
                }
            }

        }
        
        // for(auto i:adjList)
        // {
        //     cout<<(char)(i.first + 'a')<<"-->";
        //     for(auto j:adjList[i.first]) cout<<(char)(j+'a')<<",";
        //     cout<<endl;
        // }
        
        string ans = "";
        vector<bool> visited(K,0);
        
        for(int i=0;i<K;i++)
        {
            if(!visited[i]) toposort(i,adjList,visited,ans);
        }
        
        return ans;
    }
};