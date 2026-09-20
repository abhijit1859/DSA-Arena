class Solution {
public:
    int countSubstrings(string s) {
        int count=0;
        for(int i=0;i<s.length();i++){
            count+=expand(s,i,i);
            count+=expand(s,i,i+1);
        }
        return count;
    }
    
    int expand(string s,int left,int right){
        int n=s.length();
        int count=0;
        while(left>=0&&right<n&&s[left]==s[right]){
            left--;
            right++;
            count++;
        }

        return count;
    }
};