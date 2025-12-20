class Solution {
    public int beautySum(String s) {
         int bNumber=0;
        for (int i = 0; i < s.length(); i++) {
            for (int j = i + 1; j <= s.length(); j++) {
                bNumber += isBeauty(s.substring(i, j));
               
            }
        }
        return bNumber;
    }

    private static int isBeauty(String s) {
        HashMap<Character, Integer> map = new HashMap<>();

        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);   
            map.put(ch, map.getOrDefault(ch, 0) + 1);
        }

        int minFreq = Integer.MAX_VALUE;
        int maxFreq = Integer.MIN_VALUE;

        for (int freq : map.values()) {
            if (freq < minFreq) minFreq = freq;
            if (freq > maxFreq) maxFreq = freq;
        }

        return maxFreq - minFreq;
    }
}