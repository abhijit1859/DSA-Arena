class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int left=0;
        int ans=0;
        for(int right=0;right<s.length();right++){
            char c=s[right];
            mp[c]++;
            while(mp[c]>1){
                mp[s[left]]--;
                left++;
            }
            ans=max(ans,right-left+1);
        }
        return ans;
    }
};