class Solution {
    public boolean isPalindrome(String s) {
        String temp=s.toLowerCase();
        String temp1="";
        for(int i=0;i<s.length();i++){
            if(temp.charAt(i)>=97&&temp.charAt(i)<=122||temp.charAt(i)>=48&&temp.charAt(i)<=57){
                temp1=temp1+temp.charAt(i);

            } else{
                continue;
            }
        }
        String second=temp1;
        System.out.println(temp1);
        System.out.println(second);
        for(int i=0;i<second.length();i++){
            if(second.charAt((second.length()-1)-i)!=temp1.charAt(i)){
                return false;
            }
        }
        
        return true;


    }
}