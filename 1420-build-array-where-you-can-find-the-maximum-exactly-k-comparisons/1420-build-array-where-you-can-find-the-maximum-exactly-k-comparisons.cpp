class Solution {
public:
    int ans=0;
    const int mod=1e9+7;
    int n,m,k;
    int dp[51][51][101];
    int solve(int idx,int searchCost,int maxSoFar){
        if(searchCost>k) return 0;
        if(idx==n){
            return searchCost==k?1:0;
        }

        if(dp[idx][searchCost][maxSoFar]!=-1) return dp[idx][searchCost][maxSoFar];
        long long result=0;
    
        for(int num=1;num<=m;num++){
            if(num>maxSoFar){
                result+=solve(idx+1,searchCost+1,num);
            }else{
                result+=solve(idx+1,searchCost,maxSoFar);

            }
            result%=mod;
        }
        return dp[idx][searchCost][maxSoFar]=result;
    }
    int numOfArrays(int n, int m, int k) {
        this->n=n;
        this->m=m;
        this->k=k;
        memset(dp,-1,sizeof(dp));
        return solve(0,0,0);
    }
};