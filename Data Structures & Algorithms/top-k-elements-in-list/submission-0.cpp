class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //use pq - order by frequency
        priority_queue<pair<int,int>> pq;
        int count = 0;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            if(i>0 && (nums[i] == nums[i-1]) || i==0)
            {
                count++;
            }
            else{
                pq.push({count, nums[i-1]});
                count = 1;//for the new  number
            }
        }
        pq.push({count, nums[n-1]});
        vector<int> ans;
        while(k--)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
