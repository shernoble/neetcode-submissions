class Solution {
public:
    int helper(int idx, int prev, int n, vector<int> &nums, vector<vector<int>> &dp)
    {
        //base case
        if(idx >= n)
        {
            return 0;
        }
        
        if(dp[idx][prev+1]!=-1) return dp[idx][prev+1];
        //pick and compare
        int len = 0 + helper(idx+1, prev, n, nums, dp);
        if(prev == -1 || nums[idx] > nums[prev])
        {
            len =  max(1 + helper(idx+1, idx, n, nums, dp), len);
        }
        return dp[idx][prev+1] = len;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1,-1));
        return helper(0,-1,n,nums, dp);
    }
};
