class Solution {
    public String removeDuplicates(String s) {
        return remove(s);
    }
    private static String remove(String s){
        int left=0;
        int right=1;
        
        while(right<s.length()){
            if(s.charAt(left)==s.charAt(right)){
                
                s = s.substring(0,left)+s.substring(right+1);
                 
                left = Math.max(0, left - 1);
                right = left + 1;
                
            }else{
                left++;
                right++;
            }
        }
        return s;
    }
}