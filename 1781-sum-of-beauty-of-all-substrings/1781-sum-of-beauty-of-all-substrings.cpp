class Solution {
public:
    int beautySum(string s) {
        int beauty=0;
        for(int i=0;i<s.length();i++){
            map<char,int> mp;
            for(int j=i;j<s.length();j++){
                int mi=INT_MAX;
                int ma=INT_MIN;
                mp[s[j]]++;
                for(auto it:mp){
                    mi=min(mi,it.second);
                    ma=max(ma,it.second);
                }
                beauty+=ma-mi;
            }
        }
        return beauty;
    }
};