/*
Given a grid consisting of '0's(Water) and '1's(Land). Find the number of islands.
Note: An island is surrounded by water and is formed by connecting adjacent 
lands horizontally or vertically or diagonally i,e in all 8 directions.

Input:
grid = {{0,1},{1,0},{1,1},{1,0}}
Output:
1
Explanation:
The grid is-
0 1
1 0
1 1
1 0
All lands are connected.
*/

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) 
    {
        int count = 0;
        
        int m = grid.size();
        int n = grid[0].size();
        
        vector<pair<int,int>> d8 = { {-1,-1}, {-1,0}, {-1,+1}, {0,-1}, {0,+1}, {+1,-1}, {+1,0}, {+1,+1} };
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                
                if(grid[i][j]=='1')
                {
                    
                    count+=1;
                    queue<pair<int,int>> q;
                    q.push(make_pair(i,j));
                    
                    auto temp = q.front();
                    
                    
                    while(!q.empty())
                    {
                        pair<int, int> temp = q.front();
                        q.pop();
                        
                        int temp_x = temp.first;
                        int temp_y = temp.second;
                        
                        grid[temp_x][temp_y] = '0';
                        
                        for(auto d : d8)
                        {
                            int dx = d.first;
                            int dy = d.second;
                            
                            int x = temp_x + dx;
                            int y = temp_y + dy;
                            if(x>=0 && x<m && y>=0 && y<n && grid[x][y]=='1')
                            {
                                q.push(make_pair(x,y));
                                grid[x][y] = '0';
                            }
                            
                        }
                    }
                    
                }                
                
            }
        }
            
        return count;
            
    }
};