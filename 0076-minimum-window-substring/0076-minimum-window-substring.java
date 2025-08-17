class Solution {
    public String minWindow(String s, String t) {
         HashMap<Character, Integer> need = new HashMap<>();
        for (int i = 0; i < t.length(); i++) {
            char c = t.charAt(i);
            need.put(c, need.getOrDefault(c, 0) + 1);
        }
        
        HashMap<Character, Integer> window = new HashMap<>();
        int left = 0, right = 0;
        int formed = 0;
        int required = need.size();
        int minLen = Integer.MAX_VALUE;
        int start = 0;
        
        while (right < s.length()) {
            char c = s.charAt(right);
            window.put(c, window.getOrDefault(c, 0) + 1);
            
            if (need.containsKey(c) && window.get(c).intValue() == need.get(c).intValue()) {
                formed++;
            }
            
            while (formed == required) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }
                
                char leftChar = s.charAt(left);
                window.put(leftChar, window.get(leftChar) - 1);
                if (need.containsKey(leftChar) && window.get(leftChar) < need.get(leftChar)) {
                    formed--;
                }
                left++;
            }
            
            right++;
        }
        
        if (minLen == Integer.MAX_VALUE) {
            return "";
        } else {
            return s.substring(start, start + minLen);
        }
    }

}