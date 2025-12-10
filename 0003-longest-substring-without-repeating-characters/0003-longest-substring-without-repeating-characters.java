class Solution {
    public int lengthOfLongestSubstring(String s) {
        int ans=helper("",s);
        return ans;

    }

    static int helper(String p, String up){
        if(up.isEmpty()){

            return p.length();
        }
        char c = up.charAt(0);
        boolean ch=true;
        for(int i=0;i<p.length();i++){
            if(c==p.charAt(i)){
                ch=false;
                break;
            }
        }
        if(ch==false){
            return helper(p,up.substring(1));
        }else{
            return helper(p+c,up.substring(1));
        }

    }
}