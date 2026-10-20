class Solution {
public:
    vector<vector<string>> result;
    vector<string> path;
    vector<vector<string>> partition(string s) {
        solve(s,0);
        return result;
    }
    void solve(string& s,int index){
        if(index==s.length()){
            result.push_back(path);
            return;
        }
        for(int i=index;i<s.length();i++){
            if(isPalin(s,index,i)){
                path.push_back(s.substr(index,i-index+1));
                solve(s,i+1);
                path.pop_back();
            }
        }
    }
    bool isPalin(string &s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
};