class Solution {
public:
    vector<vector<string>> result;
    vector<string> path;
    vector<vector<bool>> dp;
    vector<vector<string>> partition(string s) {
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
        solve(s,0);
        return result;
    }
    void solve(string& s,int index){
        if(index==s.length()){
            result.push_back(path);
            return;
        }
        for(int i=index;i<s.length();i++){
            if(dp[index][i]){
                path.push_back(s.substr(index,i-index+1));
                solve(s,i+1);
                path.pop_back();
            }
        }
    }
    
};