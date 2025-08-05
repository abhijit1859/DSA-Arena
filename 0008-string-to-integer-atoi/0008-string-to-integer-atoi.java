class Solution {
    public int myAtoi(String s) {
        if(s.length()==0){
            return 0;
        }
        int n=s.length();
        int i=0;
        while(i<n&&s.charAt(i)==' '){
            i++;
        }
        int sign=1;
        if(i<n&&s.charAt(i)=='+'){
            i++;
        }else if(i<n&&s.charAt(i)=='-'){
            i++;
            sign=-1;
        }
        int result=0;
        while(i<n&&Character.isDigit(s.charAt(i))){
            int digit=s.charAt(i)-'0';
            if (result > (Integer.MAX_VALUE - digit) / 10) {
                return sign == 1 ? Integer.MAX_VALUE : Integer.MIN_VALUE;
            }
            result=result*10+digit;
            i++;

        }

        return sign*result;
        
    }
}