class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        int left=0;
        string ans="";
        string first=strs[0];
        string end=strs[strs.size()-1];
        for(int i=0;i<min(first.size(),end.size());i++){
            if(first[i]!=end[i]){
                return ans;
            }
            ans+=first[i];
        }
        return ans;

        
    }
};