class Solution {
public:
    vector<vector<int>> dp;
    int m,n;
    int solve(vector<vector<int>>& grid,int i,int j){
        if(i==m-1&&j==n-1){
            return max(1,1-grid[i][j]);
        }
        if(i>=m||j>=n) return INT_MAX;
        if(dp[i][j]!=-1) return dp[i][j];
        int nextMinHealth=min(solve(grid,i+1,j),solve(grid,i,j+1));
        return dp[i][j]=max(1,nextMinHealth-grid[i][j]);
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        m=dungeon.size();
        n=dungeon[0].size();
        dp.assign(m,vector<int>(n,-1));
        return solve(dungeon,0,0);
    }
};