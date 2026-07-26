class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans=0;
        int freq[3]={};
        long long left=0;
        for(int right=0;right<s.length();right++){
            freq[s[right]-'a']++;
            while(freq[0]>0&&freq[1]&&freq[2]>0){
                ans+=s.size()-right;
                freq[s[left]-'a']--;
                left++;
            }
        }
        return ans;
    }
};