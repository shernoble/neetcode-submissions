class Solution {
public:

    int helper(int idx, vector<int> &prices, bool canBuy,vector<vector<int>> &dp)
    {
        if(idx>=prices.size()) return 0;

        if(dp[idx][canBuy]!=-1) return dp[idx][canBuy];

        // with cooldown
        int buy = 0, sell = 0;
        if(canBuy)
        {
            // buy
            // dont
            // return max(-price[idx]+helper(idx+1),helper(idx+1));/
            buy = max(-prices[idx]+helper(idx+1,prices,0,dp),helper(idx+1,prices,1,dp));
        }
        else{
            // sell
            // dont
            sell = max(+prices[idx]+helper(idx+2,prices,1,dp),helper(idx+1,prices,0,dp));
        }
        return max(buy, sell);
    }

    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size()+1,vector<int>(2,-1));

        return helper(0,prices,1,dp);
    }
};
