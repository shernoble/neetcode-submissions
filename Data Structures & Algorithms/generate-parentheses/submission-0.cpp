class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string temp = "";
        helper(0,0,n,res,temp);
        return res;
    }

    void helper(int l, int r,int n, vector<string> &res, string temp)
    {
        //base case
        if(temp.size() == 2*n)
        { 
            res.push_back(temp);
            return;
        }

        //how to pick
        //pick l when : string is empty and multiple times
        // temp += '(';
        if(l < n)
            helper(l+1,r,n, res, temp + "(");

        //dont pick l or pick r when
        if(r < l)
            helper(l, r+1, n, res, temp + ")");


    }
};
