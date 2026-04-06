class Solution {
public:

    int helper(int idx,vector<int> &nums,vector<int> &dp)
    {
        // base case
        if(idx < 0){
            return 0;
        }
        if(dp[idx]!=-1) return dp[idx]; 
        // take and not take situation

        int take = nums[idx]+helper(idx-2,nums,dp);
        int not_take = 0+helper(idx-1,nums,dp);

        return dp[idx]=max(take,not_take);

    }

    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return helper(nums.size()-1,nums,dp);
    }
};
