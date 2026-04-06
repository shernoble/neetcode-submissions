class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prod1= 1;
        int prod2 =1;
        int maxi = INT_MIN;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
            {
                // reset both
                prod1 = 1;
                prod2 = 1;
                maxi = max(maxi,0);
            }
            else if(nums[i]<0)
            {
                // reset only prod1
                prod1 = 1;
                prod2*=nums[i];
                maxi = max(maxi, prod2);
            }
            else{
                prod1*=nums[i];
                prod2*=nums[i];
                maxi = max(maxi, max(prod1,prod2));
            }
        }
        return maxi;
        
    }
};
