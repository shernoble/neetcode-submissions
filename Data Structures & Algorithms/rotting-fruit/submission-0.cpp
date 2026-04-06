class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // count number of fresh fruits 
        // count number of rotten fruits
        int n = grid.size();
        int m = grid[0].size();

        int fresh = 0;
        int rotten = 0;

        queue<pair<pair<int,int>,int>> q;

        for(int i=0;i<n;i++)
        {
            for(int j= 0;j<m;j++)
            {
                if(grid[i][j]==1) fresh++;
                else if(grid[i][j]==2){
                    rotten++;
                    q.push({{i,j},0});
                }
            }
        }

        // bfs
        int max_t = 0;
        int delr[4]={-1,0,1,0};
        int delc[4]={0,1,0,-1};
        while(!q.empty())
        {
            auto node = q.front();
            q.pop();
            int row = node.first.first;
            int col = node.first.second;
            int time = node.second;

            max_t  = time;

            // check its neighbors
            for(int i=0;i<4;i++)
            {
                int nr = row+delr[i];
                int nc = col+delc[i];
                // check if valid
                // out of bounds + if fruit is present
                if(nr<n && nc<m && nr>=0 && nc>=0 && grid[nr][nc]==1){
                    grid[nr][nc]=2;
                    q.push({{nr,nc},time+1});
                    fresh--;
                }
            }
            

        }
        if(fresh == 0) return max_t;
        return -1;
    }
};
