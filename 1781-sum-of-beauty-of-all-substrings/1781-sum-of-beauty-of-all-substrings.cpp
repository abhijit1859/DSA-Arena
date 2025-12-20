class Solution {
public:
    int beautySum(string s) {
        int ans=0;
        for(int i=0;i<s.length();i++){
            map<char,int> mp;
            for(int j=i;j<s.length();j++){
                mp[s[j]]++;
                int least=INT_MAX;
                int freq=INT_MIN;
                for(auto it:mp){
                    least=min(least,it.second);
                    freq=max(freq,it.second);
                }
                ans+=freq-least;
            }
        }

        return ans;
    }
};