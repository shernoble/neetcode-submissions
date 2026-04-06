class Solution {
public:

    int helper(int row,int col, int m ,int n,vector<vector<int>> &dp)
    {
        // base cases
        // destination
        if(row == m-1 && col == n-1) return 1;
        // out of bounds
        if(row>=m || col>=n) return 0;

        if(dp[row][col]!=-1) return dp[row][col];
        // right
        int right =helper(row,col+1,m,n,dp);
        // down
        int down = helper(row+1,col,m,n,dp);
        return dp[row][col]=right+down;
    }
    int uniquePaths(int m, int n) {
        // 2d dp
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return helper(0,0,m,n,dp);
        
    }
};
