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
    bool canAttendMeetings(vector<Interval>& intervals) {
        vector<int> starts;
        vector<int> ends;
        for(auto &it:intervals)
        {
            starts.push_back(it.start);
            ends.push_back(it.end);
        }
        sort(starts.begin(),starts.end());
        sort(ends.begin(),ends.end());

        int i=0,j=0;

        int n = intervals.size();
        int count = 0;//count number of overlaps -> if none return true;
        int maxi =0 ;
        while(i<n)
        {
            if(starts[i] < ends[j]) {
                i++;
                count++;
            }
            else{
                j++;
                count--;
            }
            maxi = max(maxi, count);
        }
        return maxi<=1;
    }
};
