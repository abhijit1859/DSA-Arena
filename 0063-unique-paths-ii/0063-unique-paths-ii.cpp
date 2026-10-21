class Solution {
public:
    int m, n;
    vector<vector<int>> dp;
    int solve(int i,int j,vector<vector<int>>& grid){
        if(i>=m||j>=n) return 0;
        if(grid[i][j]==1) return 0;
        if(i==m-1&&j==n-1) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j]=solve(i,j+1,grid)+solve(i+1,j,grid);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        m=obstacleGrid.size();
        n=obstacleGrid[0].size();
        dp.assign(m,vector<int>(n,-1));
        return solve(0,0,obstacleGrid);
    }
};