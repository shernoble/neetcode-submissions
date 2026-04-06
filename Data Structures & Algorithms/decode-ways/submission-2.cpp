class Solution {
public:

    int helper(int idx, string s,vector<int> &dp)
    {
        // base case
        if(idx == s.size())
        {
            return 1;
        }
        if(dp[idx]!=-1) return dp[idx];
        int take1 =0;
        if(s[idx]!='0') take1 = helper(idx+1,s,dp);
        cout<<take1<<"\n";
        int take2 = 0;
        if(idx<s.size()-1 && stoi(s.substr(idx,2)) <= 26 && s[idx]!='0'){

            take2=helper(idx+2,s,dp);
            cout<<take2<<"\n";
        }
        return dp[idx]=take1+take2;
    }

    int numDecodings(string s) {
        vector<int> dp(s.size(),-1);
        return helper(0,s,dp);
    }
};
