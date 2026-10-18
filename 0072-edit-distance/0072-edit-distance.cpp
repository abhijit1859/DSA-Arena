class Solution {
public:
    int dp[501][501];
    int solve(string w1,string w2,int i,int j){
        int n=w1.length();
        int m=w2.length();
        if(i==n) return m-j;
        if(j==m) return n-i;

        if(dp[i][j]!=-1) return dp[i][j];

        if(w1[i]==w2[j]){
            return dp[i][j]=solve(w1,w2,i+1,j+1);
        }

        int ins=solve(w1,w2,i,j+1);
        int del=solve(w1,w2,i+1,j);
        int rep=solve(w1,w2,i+1,j+1);
        return dp[i][j]=1+min({ins,del,rep});
    }
    int minDistance(string word1, string word2) {
        memset(dp,-1,sizeof(dp));
        return solve(word1,word2,0,0);
    }
};