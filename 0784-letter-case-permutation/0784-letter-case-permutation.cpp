class Solution {
public:
    vector<string> ans;
    vector<string> letterCasePermutation(string s) {
        permutate(s,0);
        return ans;
    }
    void permutate(string &s,int idx){
        if(idx==s.length()){
            ans.push_back(s);
            return;
        }
        if(isalpha(s[idx])){
            s[idx]=tolower(s[idx]);
            permutate(s,idx+1);
            s[idx] = toupper(s[idx]);
            permutate(s,idx+1);
        }else{
            permutate(s,idx+1);
        }

    }
};