class Solution {
public:
    vector<vector<int>> dp;
    int m,n;
    vector<vector<bool>> visited;
    int solve(int i,int j,vector<vector<int>>& grid){
        if(j<0||j>=n) return INT_MAX;
        if(i==m-1) return grid[i][j];
        if(visited[i][j]) return dp[i][j];
        visited[i][j]=true;
        return dp[i][j]=grid[i][j]+min({solve(i+1,j,grid),solve(i+1,j+1,grid),solve(i+1,j-1,grid)});

    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        m=matrix.size();
        n=matrix[0].size();
        dp.assign(m,vector<int>(n,-1));
        visited.assign(m,vector<bool>(n,0));
        int ans=INT_MAX;
        for(int j=0;j<n;j++){
            ans=min(ans,solve(0,j,matrix));
        }
        return ans;
    }
};