class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        reverse(s.begin(),s.end());
        int i = 0;
        int left=0;
        int right-0;
        while (i < n) {
            while (i < n && s[i] == ' ') {
                i++;
            }
            int left = i;
            if (i == n) {
                break;
            }

            while (i < n && s[i] != ' ') {
               s[right++]=' '
            }

            revser(s.begin()+left,s.end()+right)

            
        }
    }
};