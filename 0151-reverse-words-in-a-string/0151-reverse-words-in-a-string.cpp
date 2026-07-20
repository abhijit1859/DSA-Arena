class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());
        int i=0,idx=0;
        int n=s.size();
        while(i<n){
            while(i<n&&s[i]==' '){
                i++;
            }
            if(i==n) break;
            if(idx!=0) s[idx++]=' ';
            int start=idx;
            while(i<n&&s[i]!=' '){
                s[idx++]=s[i++];
            }
            reverse(s.begin()+start,s.begin()+idx);
        }
        s.resize(idx);
        return s;
    }
};