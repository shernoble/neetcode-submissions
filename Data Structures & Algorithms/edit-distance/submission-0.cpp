class Solution {
public:

    int helper(int i, int j, string s1, string s2)
    {
        // base cases
        if(i==s1.size()) return s2.size()-j;
        if(j==s2.size()) return s1.size()-i;

        // main
        if(s1[i] == s2[j]) return 0+helper(i+1,j+1,s1,s2);

        else return 1+ min(helper(i+1,j,s1,s2),min(helper(i+1,j+1,s1,s2),helper(i,j+1,s1,s2)));

    }

    int minDistance(string word1, string word2) {
        return helper(0,0,word1,word2);
    }
};
