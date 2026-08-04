class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buyptr = 0;
        int sellptr = 0;
        int n = prices.size();
        int maxProfit = 0;
        int temp = 0;
        while( buyptr<n && sellptr<n)
        {
            temp = prices[sellptr] -prices[buyptr];
            if(temp<0)
            {
                buyptr = sellptr;
            }
            maxProfit = max(maxProfit, temp);
            sellptr++;
        }
        return maxProfit;
    }
};
