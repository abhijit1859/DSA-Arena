class Solution {
public:
    int countGoodSubstrings(string s) {
        int i=0;
        int n=s.length();
        int count=0;
        while(i<(n-2)){
            int a=s[i];
            int b=s[i+1];
            int c=s[i+2];
            if(a!=b&&b!=c&&c!=a){
                count++;
            }

            i++;
        }
        return count;
    }
};