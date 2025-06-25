class Solution {
    public int mySqrt(int x) {
        int ans = bs(x);
        System.out.println(ans);
        return ans;
    }

    private static int bs(int x) {
        if (x == 0 || x == 1) return x;

        int low = 1;
        int high = x / 2;
        int ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (mid <= x / mid) {
                ans = mid;      // store possible answer
                low = mid + 1;  // search right side for bigger value
            } else {
                high = mid - 1; // search left side
            }
        }

        return ans;
    }
}
