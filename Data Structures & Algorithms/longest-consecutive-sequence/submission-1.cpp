class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        int n= nums.size();
        unordered_set<int> mpp;
        for(int i=0;i<n;i++)
        {
            mpp.insert(nums[i]);
        }
        int longest = 0, temp = 1;
        int curr, prev;
        for(int i=0;i<n;i++)
        {
            curr = nums[i];
            if(mpp.find(curr-1) == mpp.end())
            {
                temp = 1;
                while(mpp.find(curr+temp) != mpp.end())
                {
                    temp++;
                }
                longest = max(longest, temp);
            }

        }

        return longest;
    }
};
