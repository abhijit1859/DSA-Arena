#include <bits/stdc++.h>
using namespace std;

class Solution {
    int dp[1001][1001];  

public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        
         
        memset(dp, -1, sizeof(dp));
        
        return longest(text1, text2, n, m);
    }

private:
    int longest(string &text1, string &text2, int i, int j) {
        if (i == 0 || j == 0) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        if (text1[i-1] == text2[j-1]) {
            return dp[i][j] = 1 + longest(text1, text2, i-1, j-1);
        } else {
            return dp[i][j] = max(longest(text1, text2, i-1, j),
                                  longest(text1, text2, i, j-1));
        }
    }
};
