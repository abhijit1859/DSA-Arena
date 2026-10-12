class Solution {
public:
    int solve(vector<vector<int>>& pairs,int i,int prev){
        if(i>=pairs.size()) return 0;
        if(dp[i][prev+1]!=-1) return dp[i][prev+1];
        int skip=solve(pairs,i+1,prev);
        int take=0;
        if(prev==-1||pairs[i][0]>pairs[prev][1]){
            take=1+solve(pairs,i+1,i);
        }
        return dp[i][prev+1]=max(take,skip);
    }
    vector<vector<int>> dp;
    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();
        sort(pairs.begin(),pairs.end());
        dp.assign(n,vector<int>(n+1,-1));
        return solve(pairs,0,-1);
    }
};