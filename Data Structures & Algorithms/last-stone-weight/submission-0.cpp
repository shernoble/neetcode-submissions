class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int,vector<int>> pq;
        for(auto it: stones)
        {
            pq.push(it);
        }
        int first,second;
        while(pq.size()>1)
        {
            first = pq.top();
            pq.pop();
            second = pq.top();
            pq.pop();
            if(first!=second)
            {
                pq.push(abs(first-second));
            }

        }
        if(!pq.empty()) return pq.top();
        return 0;
    }
};
