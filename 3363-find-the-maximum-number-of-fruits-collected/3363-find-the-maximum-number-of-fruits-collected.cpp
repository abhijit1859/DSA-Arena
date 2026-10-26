class Solution {
public:
    int n;
    vector<vector<int>> dp2;
    vector<vector<int>> dp3;
    vector<vector<int>> fruits;
    int child2(int i,int j){
        if(i==n-1&&j==n-1) return fruits[i][j];
        if(j>=n||j<=i||j<0){
            return INT_MIN/2;
        }
        if(dp2[i][j]!=-1) return dp2[i][j];

        int best=max({child2(i+1,j-1),child2(i+1,j+1),child2(i+1,j)});
        return dp2[i][j]=fruits[i][j]+best;
    }
    int child3(int i,int j){
        if(i==n-1&&j==n-1) return fruits[i][j];

        if(i>=n||i<=j||i<0) return INT_MIN/2;
        if(dp3[i][j]!=-1) return dp3[i][j];

        int best=max({child3(i-1,j+1),child3(i+1,j+1),child3(i,j+1)});
        return dp3[i][j]=fruits[i][j]+best;
    }
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        n=fruits.size();
    
        this->fruits=fruits;
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=fruits[i][i];
        }

        dp2.assign(n,vector<int>(n,-1));
        dp3.assign(n,vector<int>(n,-1));
        ans+=child2(0,n-1)-fruits[n-1][n-1];
        ans+=child3(n-1,0)-fruits[n-1][n-1];
        return ans;
    }
};