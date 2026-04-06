class Solution {
public:
    // vector<int> 
    vector<vector<int>> threeSum(vector<int>& nums) {
        // for each value do two sum on array
        // sort to remove duplicates
        vector<vector<int>> ans;
        // set<vector<int>> st;
        sort(nums.begin(),nums.end());
        for(int k = 0;k<nums.size();k++)
        {
            // arr[k] is number 3
            if(nums[k]>0) break;
            if(k>0 && nums[k]==nums[k-1]) continue;
            int i=k+1;
            int j = nums.size()-1;
            while(i<j)
            {
                // if(arr)
                int sum = nums[i]+nums[j]+nums[k];
                if(sum == 0)
                {
                    ans.push_back({nums[i],nums[j],nums[k]});
                    i++;j--;
                    while(i<j && nums[i]==nums[i-1]) i++;
                }
                else if(sum<0) i++;
                else j--;

            }
        }

        return ans;

    }
};
