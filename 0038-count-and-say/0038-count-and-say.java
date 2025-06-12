class Solution {
    public String countAndSay(int n) {
        return count(n);
    }

    private static String count(int n){
        if (n==1){
            return "1";
        }

        String value = count(n-1);
        String result = "";
        for(int i=0;i<value.length();i++){
            char ch = value.charAt(i);
            int count = 1;
            while(i<value.length()-1&&value.charAt(i)==value.charAt(i+1)){
                count++;
                i++;
            }

            result+=String.valueOf(count)+String.valueOf(ch);
        }
        return result;

    }
}