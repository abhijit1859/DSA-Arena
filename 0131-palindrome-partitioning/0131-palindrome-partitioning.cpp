class Solution {
public:
    vector<vector<string>> result;
    vector<vector<string>> partition(string s) {
        vector<string> path;
        solve(s,path,0);
        return result;
    }

    void solve(string s,vector<string>& path,int start){
        if(start==s.size()){
            result.push_back(path);
        }

        for(int end=start;end<s.size();end++){
            if(isPallin(s,start,end)){
                path.push_back(s.substr(start,end-start+1));
                solve(s,path,end+1);
                path.pop_back();
            }
        }
    }
    bool isPallin(string s,int l,int r){
        while(l<r){
            if(s[l]!=s[r]){
                return 0;
            }
            l++;
            r--;
        }
        return 1;
    }
};