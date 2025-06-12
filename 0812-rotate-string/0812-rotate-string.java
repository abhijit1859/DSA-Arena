class Solution {
    public boolean rotateString(String s, String goal) {
        if (s.length() != goal.length()) return false;

        String solution = s + s;
        return solution.contains(goal);
    }

     
}