class Solution {
    public int lengthOfLongestSubstring(String s) {
        HashSet<Character> set = new HashSet<>();
      
         
         int j=0;
        
         int maxlen =0;
         for(int i=0;i<s.length();i++){
            char curr = s.charAt(i);
            while (set.contains(curr)) {
                set.remove(s.charAt(j));
                j++;
            }
            set.add(curr);
            maxlen= Math.max(maxlen,i - j + 1);

         }
         return maxlen;
    }
}