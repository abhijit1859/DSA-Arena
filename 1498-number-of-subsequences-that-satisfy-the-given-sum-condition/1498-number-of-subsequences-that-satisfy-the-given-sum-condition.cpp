class Solution {
public:
    long long power(long long base, int exp) {
        long long res = 1;
        const long long mod = 1e9 + 7;

        while (exp > 0) {
            if (exp & 1) {
                res = (res * base) % mod;
            }

            base = (base * base) % mod;
            exp /= 2;
        }

        return res;
    }
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int r = n - 1;
        int res = 0;
        int mod = 1e9 + 7;
        for (int i = 0; i < n; i++) {
            while (i <= r && nums[i] + nums[r] > target) {
                r--;
            }
            if (i > r)
                break;
            res = (res + power(2, r - i)) % mod;
        }
        return res;
    }
};