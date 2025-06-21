class Solution {
    public List<String> restoreIpAddresses(String s) {
        List<String> list = new ArrayList<>();
        solve(s, 0, 0, "", list);
        return list;
    }

    private static void solve(String s, int idx, int parts, String curr, List<String> list) {
        int n = s.length();

        // ✅ base case: if 4 parts and whole string used
        if (parts == 4 && idx == n) {
            list.add(curr.substring(0, curr.length() - 1)); // remove last '.'
            return;
        }

        // ❌ Stop early if we already have 4 parts or idx exceeds length
        if (parts >= 4 || idx >= n) return;

        // ✅ Try segments of length 1 to 3
        for (int len = 1; len <= 3 && idx + len <= n; len++) {
            String segment = s.substring(idx, idx + len);
            if (isValid(segment)) {
                solve(s, idx + len, parts + 1, curr + segment + ".", list);
            }
        }
    }

    private static boolean isValid(String s) {
        // ✅ "0" is valid, but "01", "001", etc. are not
        if (s.length() > 1 && s.charAt(0) == '0') return false;

        int num = Integer.parseInt(s);
        return num >= 0 && num <= 255;
    }
}
