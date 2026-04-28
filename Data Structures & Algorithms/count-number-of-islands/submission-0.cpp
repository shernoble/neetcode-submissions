class Solution {
private:
    void helper_dfs(int i, int j, vector<vector<char>>& grid, vector<vector<int>> &vis)
    {
        //base case for recursion
        if(grid[i][j] == '0' || vis[i][j]) return;

        vis[i][j] = 1;
        //go in all four directions
        if(i-1 >= 0)
            helper_dfs(i-1,j,grid,vis);
        if(i+1 < grid.size())
            helper_dfs(i+1,j,grid,vis);
        if(j-1 >= 0)
            helper_dfs(i,j-1,grid,vis);
        if(j+1 < grid[0].size())
            helper_dfs(i,j+1,grid,vis);
        return;
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> vis(rows,vector<int>(cols));
        for(int i=0; i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                if(grid[i][j] == '1' && !vis[i][j])
                {
                    helper_dfs(i,j,grid, vis);
                    count++;
                }
            }
        }
        return count;
    }
};
