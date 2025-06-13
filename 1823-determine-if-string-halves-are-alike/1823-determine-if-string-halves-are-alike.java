class Solution {
    public boolean halvesAreAlike(String s) {
        int length = s.length();
        String s1 = s.substring(0,length/2);
        String s2 = s.substring(length/2,length);
        int c1 = countVowels(s1);
        int c2 = countVowels(s2);
        return c1==c2;
    }
    private static int countVowels(String s) {
        String vowels = "aeiouAEIOU";
        int count = 0;

        for (int i = 0; i < s.length(); i++) {
            if (vowels.indexOf(s.charAt(i)) != -1) {
                count++;
            }
        }

        return count;
    }
}