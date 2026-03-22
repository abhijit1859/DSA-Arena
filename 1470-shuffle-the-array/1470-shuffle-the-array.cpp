class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int i = 0;
        int j = n;
        int pointer = 0;

        vector<int> ans(2 * n);

        while (pointer < 2 * n) {
            ans[pointer++] = nums[i++];
            ans[pointer++] = nums[j++];
        }

        for (int num : ans) {
            cout << num << " ";
        }

        return ans;

    }
};