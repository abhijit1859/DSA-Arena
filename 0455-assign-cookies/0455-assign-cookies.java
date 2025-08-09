 
class Solution {
    public int findContentChildren(int[] g, int[] s) {
        Arrays.sort(g);
        Arrays.sort(s);
        int left = 0;  
        int count = 0;

        for (int i = 0; i < s.length && left < g.length; i++) {
            if (s[i] >= g[left]) {
                count++;
                left++;
            }
        }
        return count;
    }
}
