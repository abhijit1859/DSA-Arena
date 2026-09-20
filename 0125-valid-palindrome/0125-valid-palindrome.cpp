class Solution {
public:
    bool isPalindrome(string s) {
        string n;
        for(int i=0;i<s.length();i++){
            char c=s[i];
            if (isalnum(c)) {
                n += tolower(c);
            }
        }
        string rev = n;
        
        reverse(rev.begin(), rev.end());
         
        return rev == n;
    }
};