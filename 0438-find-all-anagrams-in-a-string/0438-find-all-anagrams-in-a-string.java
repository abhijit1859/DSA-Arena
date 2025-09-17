class Solution {
    public List<Integer> findAnagrams(String s, String p) {
        List<Integer> list = new ArrayList();
        if(s.length()<p.length()){
            return list;
        }
        int[] pCount = new int[26];
        int[] window = new int[26];
        for(char c:p.toCharArray()){
            pCount[c-'a']++;
        }

        for(int i=0;i<p.length();i++){
            window[s.charAt(i)-'a']++;
        }

        if(Arrays.equals(window,pCount)){
            list.add(0);
        }

        for(int i=p.length();i<s.length();i++){
            window[s.charAt(i)-'a']++;

            window[s.charAt(i - p.length()) - 'a']--;

            if(Arrays.equals(window,pCount)){
                list.add(i-p.length()+1);
            }
        }
        return list;
    }
}