class Solution {
public:
    int myAtoi(string s) {
        if(s.length()==0){
            return 0;
        }
        int i=0;
        int n=s.length();
        while(i<n&&s[i]==' '){
            i++;
        }
        int sign=1;
        if(i<n&&s[i]=='+'){
            sign=1;
            i++;
        }else if(i<n&&s[i]=='-'){
            sign=-1;
            i++;
        }
        while(i<n&&s[i]=='0'){
            i++;
        }
        long long result=0;

        while(i<n&&isdigit(s[i])){
            int digit=s[i]-'0';
            
            if (result > (INT_MAX - digit) / 10) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }
            result=result*10+digit;
            i++;
        }
        return result*sign;

    }
};