class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0, end = 0;
        unordered_map<char, int> mpp;
        int n = s.size();
        int prev =-1;
        int maxlen = 1;
        if(s.empty()) return 0;
        while(start <n && end<n)
        {
            if(mpp.find(s[end]) == mpp.end() || mpp[s[end]] == -1)
            {
                mpp[s[end]] = end;
                end++;
            }
            else
            {
                maxlen = max(maxlen, end-start);
                //found repeat
                prev = mpp[s[end]];
                while(start < prev+1)
                {
                    mpp[s[start]] = -1;
                    start++;
                }
            }
        }
        maxlen = max(maxlen, end-start);
        return maxlen;
    }
};
