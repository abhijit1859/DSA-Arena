class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length()<=1){
            return s;
        }
        int n=s.length();
        string LPS="";
        for(int i=1;i<s.length();i++){
            //odd
            int low=i;
            int high=i;
            while (low >= 0 && high < n && s[low] == s[high]) {
                low--;
                high++;
            }

            string p=s.substr(low + 1, high - low - 1);
            if(p.length()>LPS.length()){
                LPS=p;
            }

            //odd
            low=i-1;
            high=i;
            while (low >= 0 && high < n && s[low] == s[high]) {
                low--;
                high++;
            }

            p=s.substr(low + 1, high - low - 1);
            if(p.length()>LPS.length()){
                LPS=p;
            }
        }

        return LPS;
    }
};