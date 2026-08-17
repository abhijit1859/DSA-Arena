class Solution {
public:
    vector<vector<string>> result;
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        solve(s,0,temp);
        return result;

    }
    void solve(string s,int start,vector<string> temp){
        if(start==s.size()){
            result.push_back(temp);
        }
        for(int i=start;i<s.size();i++){
            if(isPallin(s.substr(start,i-start+1))){
                temp.push_back(s.substr(start,i-start+1));
                solve(s,i+1,temp);
                temp.pop_back();
            }
        }
    }
    bool isPallin(string s){
        int l=0;
        int r=s.size()-1;
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