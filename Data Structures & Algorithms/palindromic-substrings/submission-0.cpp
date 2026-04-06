#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int countPalindromicSubstrings(int i, int j, string& s, vector<vector<int>>& memo) {
        if (i > j) return 0;  // Base case: no substring
        
        if (memo[i][j] != -1) return memo[i][j];  // Return already computed value

        // Check if the current substring s[i..j] is a palindrome
        int count = 0;
        if (isPal(i, j, s)) {
            count = 1;  // Count this palindrome
        }
        
        // Recursive cases: move `i` and `j` to consider other substrings
        count += countPalindromicSubstrings(i + 1, j, s, memo); // Exclude s[i]
        count += countPalindromicSubstrings(i, j - 1, s, memo); // Exclude s[j]
        count -= countPalindromicSubstrings(i + 1, j - 1, s, memo); // Overcount correction

        return memo[i][j] = count;
    }

    bool isPal(int i, int j, string& s) {
        while (i <= j) {
            if (s[i++] != s[j--]) return false;
        }
        return true;
    }

    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<int>> memo(n, vector<int>(n, -1)); // Memoization array
        return countPalindromicSubstrings(0, n - 1, s, memo);
    }

};
