class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> set;
        int left=0;
        int maxLen=0;
        for(int right=0;right<s.length();right++){
            char ch=s[right];
            while(set.count(ch)){
                set.erase(s[left]);
                left++;
            }
            set.insert(ch);
            maxLen=max(right-left+1,maxLen);
        }
        return maxLen;

    }
};