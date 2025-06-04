class Solution {
    public char findKthBit(int n, int k) {
        String m = find(n);
        return m.charAt(k-1);
            }

             private static String invert(String s) {
        StringBuilder sb = new StringBuilder();
        for (char c : s.toCharArray()) {
            sb.append(c == '0' ? '1' : '0');
        }
        return sb.toString();
    }

    private static String reverse(String s) {
        return new StringBuilder(s).reverse().toString();
    }

    private static String find(int n){
        if(n==1){
            return "0";
        }
        String prev = find(n-1);
        String result = prev + '1' + reverse(invert(prev));

        return result;
    }
    
   
 
}