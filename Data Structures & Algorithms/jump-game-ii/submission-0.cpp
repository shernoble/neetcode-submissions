class Solution {
public:

    int helper(int idx, vector<int> &arr, int n,vector<int> &dp)
    {
        if(idx>=n ) return 1e9;
        if(idx == n-1) return 0;

        if(dp[idx]!=-1) return dp[idx];

        int mini = 1e9;

        for(int i=1;i<=arr[idx];i++)
        {
            int jumps = 1+helper(idx+i,arr,n,dp);

            mini = min(mini, jumps);

        }

        return dp[idx]=mini;
    }

    int jump(vector<int>& nums) {

        int n = nums.size();
        if(n==1) return 0;
        vector<int> dp(n,-1);

        return helper(0,nums,n,dp);
    }
};