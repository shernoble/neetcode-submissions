class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        helper(0,nums, temp, res);
        return res;
    }
private:
    void helper(int idx, vector<int> &nums, vector<int> &temp, vector<vector<int>> &res )
    {
        //base case
        if(idx == nums.size())
        {
            res.push_back(temp);
            return;
        }

        //pick
        temp.push_back(nums[idx]);
        helper(idx+1, nums, temp, res);

        //not-pick
        temp.pop_back();
        helper(idx+1,nums,temp,res);
    }
};
