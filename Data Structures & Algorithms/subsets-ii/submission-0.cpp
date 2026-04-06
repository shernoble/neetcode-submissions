class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        //can use set to remove dups - additional overhead with space
        sort(nums.begin(), nums.end());
        vector<int> temp;
        vector<vector<int>> res;
        helper(0,nums, temp, res);
        return res;
    }

private:
    void helper(int i, vector<int> &nums, vector<int> &temp, 
    vector<vector<int>> &res)
    {
        //base case
        if(i == nums.size())
        {
            res.push_back(temp);
            return;
        }

        //pick
        temp.push_back(nums[i]);
        helper(i+1, nums, temp, res);

        //dont pick
        temp.pop_back();
        while(i + 1 < nums.size() && nums[i] == nums[i+1])
        {
            i++;
        }
        helper(i + 1, nums, temp, res);
    }
    
};

