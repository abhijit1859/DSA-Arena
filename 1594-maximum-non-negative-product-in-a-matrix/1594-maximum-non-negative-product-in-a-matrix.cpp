class Solution {
public:
    using ll=long long;
    vector<vector<pair<ll,ll>>> dp;
    vector<vector<bool>> visited;
    int m,n;
    const int MOD=1e9+7;
    pair<ll,ll> solve(vector<vector<int>>& grid,int i,int j){
        if (i == m - 1 && j == n - 1) {
            return {grid[i][j], grid[i][j]};
        }
        if(visited[i][j]) return dp[i][j];
        ll maxVal=LONG_MIN;
        ll minVal=LONG_MAX;

        //explore down
        if(i<m-1){
            auto [downMax,downMin]=solve(grid,i+1,j);
            ll a=grid[i][j]*downMax;
            ll b=grid[i][j]*downMin;
            maxVal=max({maxVal,a,b});
            minVal=min({minVal,a,b});
        }

        if(j<n-1){
            auto [rightMax,rightMin]=solve(grid,i,j+1);
            ll a=grid[i][j]*rightMax;
            ll b=grid[i][j]*rightMin;
            maxVal=max({maxVal,a,b});
            minVal=min({minVal,a,b});
        }

        visited[i][j]=true;
        return dp[i][j]={maxVal,minVal};
    }
    int maxProductPath(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        dp.assign(m,vector<pair<ll,ll>>(n));
        visited.assign(m, vector<bool>(n, false));
        auto [maxProduct,minProduct]=solve(grid,0,0);
        return maxProduct < 0 ? -1 : maxProduct % MOD;

    }
};