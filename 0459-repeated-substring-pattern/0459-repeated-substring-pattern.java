class Solution {
    public boolean repeatedSubstringPattern(String s) {
        int n=s.length();
        for(int l=n/2;l>=1;l--){
            if(n%l==0){
                int times=n/l;
                String pattern = s.substring(0,l);
                String subStr="";
                while (times > 0) {
    subStr += pattern;
    times--;
}
                if(subStr.equals(s)
){
                    return true;
                }
            }
        }
        return false;
    }
}