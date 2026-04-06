class Solution {
public:
    bool singlesafe(string &s,int i,int n){
        // takes in curr index, therefore no need to check index validity
        // check nxt is not 0
        if(i<n-1) return !(s[i+1]==0);
        return true;
    }
    bool doublesafe(string &s, int i,int n){
        // next two indices are within range
        if(i+1>=n) return false;

        // check nxt i+2 is not 0
        if(i+1<n-1){
            if(s[i+2]=='0') return false;
        }

        // the double int is within range [1,26]-stoi
        string subs=s.substr(i,2) ;
        if(!(stoi(subs)<=26)) return false;
        return true;
        

    }
    int helper(string &s,int idx,int n,vector<int> &dp){

        if(idx==n) return 1;
        if(s[idx]=='0') return 0;
        // single
        if(dp[idx]!=-1) return dp[idx];
        int left=0;
        if(singlesafe(s,idx,n)){
            left=helper(s,idx+1,n,dp);
        }
        int right=0;
        // double
        if(doublesafe(s,idx,n)){
            right=helper(s,idx+2,n,dp);
        }

        return dp[idx]=left+right;

    }
    int numDecodings(string s) {
        // stoi
        int n=s.size();
        vector<int> dp(n+1,-1);
        return helper(s,0,n,dp);
        // single
    }
};
