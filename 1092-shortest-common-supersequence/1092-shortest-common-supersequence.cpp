class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n=str1.length();
        int m=str2.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1));
        for(int i=0;i<=n;i++){
            dp[i][m]=n-i;
        }
        for(int j=0;j<=m;j++){
            dp[n][j]=m-j;
        }

        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(str1[i]==str2[j]){
                    dp[i][j]=1+dp[i+1][j+1];
                }else{
                    dp[i][j]=1+min(dp[i+1][j],dp[i][j+1]);
                }
            }
        }
        int i=0,j=0;
        string s="";
        while(i<n&&j<m){
            if(str1[i]==str2[j]){
                s+=str1[i];
                i++;
                j++;
            }else if(dp[i+1][j]<=dp[i][j+1]){
                s+=str1[i];
                i++;
            }else{
                s+=str2[j];
                j++;
            }
        }
        while(i<n){
            s+=str1[i];
            i++;
        }
        while(j<m){
            s+=str2[j];
            j++;
        }
        return s;
    }
};