class Solution {
public:

    void bfs(int i,int j,vector<vector<int>> &grid,vector<vector<int>> &vis)
    {
        int n = grid.size();
        int m = grid[0].size();
        vis[i][j]=1;
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{i,j}});
        int dist = 0;
        while(!q.empty())
        {
            int len = q.size();

            for(int k=0 ;k<len;k++)
            {
                int dis = q.front().first; 
                int row = q.front().second.first;
                int col = q.front().second.second;
                vis[row][col]=1;
                q.pop();

                grid[row][col] = min(grid[row][col],dist);

                // add the neighboring cells if land as well
                int delr[4]={-1,0,1,0};
                int delc[4]={0,1,0,-1};

                for(int p = 0;p<4;p++)
                {
                    int nr = row+delr[p];
                    int nc = col+delc[p];

                    // if cell is valid
                    if(nr<n && nc<m && nr>=0 && nc>=0 && 
                    dis+1<grid[nr][nc]){
                        q.push({dis+1,{nr,nc}});
                    }
                }
            }
            dist++;

            
        }
        return ;
    }

    void islandsAndTreasure(vector<vector<int>>& grid) {
        // find the treasure chest
        // start bfs from there
        int n=grid.size();
        int m=grid[0].size();
        

        for(int i=0;i<n;i++)
        {
            for(int j =0;j<m;j++)
            {
                if(grid[i][j]==0)
                {
                    vector<vector<int>> vis(n,vector<int>(m,0));
                    // this is the treasure
                    bfs(i,j,grid,vis);
                }
            }
        }
    }
};
