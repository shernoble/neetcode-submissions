class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();

        int low = 0;
        int high = n-1;

        while(low<=high)
        {
            int mid = low + (high - low) /2;

            if(nums[mid] == target) return mid;

            // chekc if left is sorted
            if(nums[low] <= nums[mid]){
                // sorted
                if(target>=nums[low] && target<=nums[mid])
                {
                    // target lies in lhs
                    high = mid -1;
                }
                else{
                    // move to rhs
                    low = mid +1;
                }
            }

            else 
            {
                // rhs is sorted
                if(target>=nums[mid] && target<=nums[high])
                {
                    low = mid +1;
                }
                else{
                    // move to lhs
                    high = mid -1;
                }
            }
        }

        return -1;
    }
};