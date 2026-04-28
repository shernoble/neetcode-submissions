class Solution {
public:
    int helper(int i, vector<int> &nums,vector<int> &dp)
    {
        if(i >= nums.size()) return 0;
        if(dp[i] != -1) return dp[i];
        return dp[i] = max(nums[i]+helper(i+2,nums,dp),helper(i+1,nums,dp));
    }
    int rob(vector<int>& nums) {
        // 2vectors

        if(nums.size() == 1) return nums[0];
        int n = nums.size();
        vector<int> sub1(nums.begin(),nums.end()-1);
        vector<int> sub2(nums.begin()+1,nums.end());
        vector<int> dp1(sub1.size(), -1);
        vector<int> dp2(sub2.size(), -1);
        
        return max(helper(0,sub1,dp1), 
        helper(0,sub2,dp2));
    }
};
