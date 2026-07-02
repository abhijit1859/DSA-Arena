class Solution {
public:
    bool canBloom(vector<int>& bloomDays, int m, int k, int day) {
        int consecutive = 0;
        int bouquets = 0;

        for (int i = 0; i < bloomDays.size(); i++) {
            if (bloomDays[i] <= day) {
                consecutive++;
            } else {
                consecutive = 0;
            }

            if (consecutive == k) {
                bouquets++;
                consecutive = 0;

                if (bouquets == m)
                    return true;
            }
        }

        return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        if ((long long)m * k > bloomDay.size())
            return -1;

        int low = INT_MAX;
        int high = INT_MIN;

        for (int d : bloomDay) {
            low = min(low, d);
            high = max(high, d);
        }

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canBloom(bloomDay, m, k, mid)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};