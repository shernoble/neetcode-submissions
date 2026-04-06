class Solution {
public:

    int helper(int idx,int n, vector<int> &cost)
    {
        cout<<idx<<"\n";
        if(idx == n) return 0;
        if(idx>n) return 1e9;

        int left = 1e9,right=1e9;
        // if(idx-1>=0)
        left = cost[idx]+helper(idx+1,n,cost);
        // if(idx-2>=0)
        right = cost[idx]+helper(idx+2,n,
        cost);
        return min(left, right);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        
        int n = cost.size();
        return min(helper(0,n,cost),helper(1,n,cost));
    }
};
