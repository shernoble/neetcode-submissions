class Solution {
public:
    bool canJump(vector<int>& nums) {
            int n = nums.size();

            int idx = n-1;

            for(int i = idx;i>=0;i--)
            {
                if(idx-i <=nums[i] ){
                    idx = i;
                }
            }
            return idx == 0;
    }
};
