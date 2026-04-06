class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& ogqueries) {
        // minheap to store the minimum sized interval
        // hash map to store the actual positions
        // sort the intervals and the queries
        // if queries are sorted, we will always end up with the minimum one that is within the limits
        // when it is poped it means that it is not going to be used for future queries asw
        unordered_map<int,int> mpp;
        vector<int> queries=ogqueries;
        // for(int i=0;i<queries.size();i++)
        // {
        //     mpp[queries[i]]=i;
        // }
        sort(queries.begin(),queries.end());
        sort(intervals.begin(),intervals.end());

        // min heap with (size, end)
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> ans(queries.size(),-1);
        int j=0;
        for(int i=0;i<queries.size();i++)
        {
            while(j<intervals.size() && intervals[j][0] <= queries[i] ){
                // adding for each query
                // intervals is sorted

                int left=intervals[j][0];
                int right = intervals[j][1];
                pq.push({right-left+1, right});
                j++;
            }
            while(!pq.empty() && pq.top().second < queries[i])pq.pop();
            // ans[mpp[queries[i]]] = pq.top()
            // if(pq.empty()) ans[mpp[queries[i]]] = -1;
            if(!pq.empty()) mpp[queries[i]] = pq.top().first;
            else mpp[queries[i]]=-1;
        }

        for(int i=0;i<queries.size();i++)
        {
            ans[i]=mpp[ogqueries[i]];
        }
        return ans;


    }
};