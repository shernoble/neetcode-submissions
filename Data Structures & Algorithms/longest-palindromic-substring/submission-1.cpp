class Solution {
public:
    string longestPalindrome(string s) {
        // idea is to have a more efficient way to check if it is a palindrome and 
        int n = s.size();
        int resLen =0;
        string res = "";
        // if odd len
        // if(n%2)
        // {
        for(int i=0;i<n;i++)
        {
                // work outwards
                int l=i,r=i;
                while(l>=0 && r<n && s[l]==s[r])
                {
                    if(r-l+1 > resLen)
                    {
                        res = s.substr(l,r-l+1);
                        resLen = r-l+1;
                    }
                    l--;r++;
                }
            // }
        // }
        // else{
            // for(int i=0;i<n;i++)
            // {
                // work outwards
                l=i,r=i+1;
                while(l>=0 && r<n && s[l]==s[r])
                {
                    if(r-l+1 > resLen)
                    {
                        res = s.substr(l,r-l+1);
                        resLen = r-l+1;
                    }
                    l--;r++;
                }
            
        }

        return res;
    }
};
