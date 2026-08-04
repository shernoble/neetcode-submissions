class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int n= nums.size();
        vector<int> pref(n+2,1);
        vector<int> suff(n+2,1);

        for(int i =1;i<n+1;i++)
        {
            pref[i] = pref[i-1] * nums[i-1];
        }

        // temp = 1;
        for(int i = n;i>0;i--)
        {
            suff[i] = suff[i+1] * nums[i-1];
        }

        vector<int> output;
        // int prev = 1;
        for(int i =1;i<n+1;i++)
        {
            if(i == 1)
                output.push_back(suff[i+1]);
            else if(i==n)
                output.push_back(pref[i-1]);
            else
                output.push_back(pref[i-1]*suff[i+1]);
        }

        return output;
        
    }
};
