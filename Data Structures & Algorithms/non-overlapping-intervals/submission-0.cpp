class Solution {
public:

    bool isOverlapping(vector<int> v1, vector<int> v2)
    {

        return (v2[0]>=v1[0] && v2[0]<=v1[1]);
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // eliminate the one with the greater end
        int count = 0;
        sort(intervals.begin(),intervals.end());
        int prevEnd = intervals[0][1];

        for(int i = 1;i<intervals.size();i++)
        {
            
            if(prevEnd>intervals[i][0]){
                // find one with greater end
                count++;
                prevEnd = min(prevEnd, intervals[i][1]);
            }
            else prevEnd = intervals[i][1];
        }
    return count;

    }
};
