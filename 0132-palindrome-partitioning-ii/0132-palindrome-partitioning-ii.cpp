class Solution {
public:
    vector<int> path;
    vector<vector<bool>> dp;
    vector<int> memo;
    int solve(string& s,int index){
        int n=s.size();
        if(n==index) return 0;
        if(memo[index]!=-1) return memo[index];
        int ans=INT_MAX;
        for(int j=index;j<n;j++){
            if(dp[index][j]){
                if(j==n-1){
                    ans=0;
                    break;
                }
                ans=min(ans,1+solve(s,j+1));
            }
        }
        return memo[index]=ans;
    }
    int minCut(string s) {
        int n=s.size();
        dp.assign(n,vector<bool>(n,false));
        for(int L=1;L<=n;L++){
            for(int i=0;i<n-L+1;i++){
                int j=i+L-1;
                if((s[i]==s[j])&&((L<=2)||dp[i+1][j-1])){
                    dp[i][j]=true;
                }
            }
        }
        memo.assign(n,-1);
        return solve(s,0);

    }
};