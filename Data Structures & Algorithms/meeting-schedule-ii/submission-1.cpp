/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        // answer will be the max number of meetings that overlap
        // 0,5,15
        // 10,20,40
        vector<int> start;
        vector<int> end;
        int n = intervals.size();
        for(int i=0;i<n;i++)
        {
            start.push_back(intervals[i].start);
            end.push_back(intervals[i].end);
        }
        sort(start.begin(),start.end());
        sort(end.begin(), end.end());

        int i=0, j=0, count =0;
        int maxi =INT_MIN;
        while(i <n)
        {
            if(start[i] < end[j])
            {
                //overlap
                i++;
                count++;
            }
            else
            {
                j++;
                count--;
            }
            maxi = max(maxi, count);
        }
        return max(maxi,0);
    }
};
