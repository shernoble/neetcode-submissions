class Solution {
public:

    int helper(int row,int col, int m ,int n)
    {
        // base cases
        // destination
        if(row == m-1 && col == n-1) return 1;
        // out of bounds
        if(row>m || col>n) return 0;
        // right
        int right =helper(row,col+1,m,n);
        // down
        int down = helper(row+1,col,m,n);
        return right+down;
    }
    int uniquePaths(int m, int n) {
        // 2d dp

        return helper(0,0,m,n);
        
    }
};
