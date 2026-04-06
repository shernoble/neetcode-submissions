class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> temp;
        vector<vector<int>> res;
        helper(0,0,target,nums, temp, res);

        return res;
    }

private:
    void helper(int i, int sum,int target, vector<int> &nums, vector<int> &temp, vector<vector<int>> &res)
    {
        if(sum == target){
            res.push_back(temp);
            return;
        }
        
        //base case - if we reach the end of array or exceed target
        if(i == nums.size() || sum > target)
        {
            return;
        }

        //pick
        temp.push_back(nums[i]);
        helper(i, sum+nums[i], target, nums, temp, res);
    

        //not pick
        temp.pop_back();
        helper(i+1,sum, target, nums, temp, res);
    }
};
