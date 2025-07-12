class Solution {
    public int uniquePaths(int m, int n) {
        int[][] dp = new int[m + 1][n + 1];  
        return unique(m, n, dp);
    }

    private int unique(int m, int n, int[][] dp) {
        if (m == 1 && n == 1) {
            return 1;
        }
        if (m == 0 || n == 0) {
            return 0;
        }

       
        if (dp[m][n] != 0) {
            return dp[m][n];
        }

       
        dp[m][n] = unique(m - 1, n, dp) + unique(m, n - 1, dp);
        return dp[m][n];
    }
}
