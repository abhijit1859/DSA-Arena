class Solution {
    public boolean detectCapitalUse(String word) {
        int count=0;
        for(int i=0;i<word.length();i++){
            if(word.charAt(i)>=65&&word.charAt(i)<=90){
                count++;
            }
        }
        System.out.println(count);
        if(count==1&&word.charAt(0)>=65&&word.charAt(0)<=90){
            return true;
        }
        if(count==word.length()||count==0){
            return true;
        }else{
            return false;
        }
    }
}