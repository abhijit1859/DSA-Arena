class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> freq;
        unordered_map<char, int> window;
        vector<int> ans;
        for (char c : p) {
            freq[c]++;
        }
        int left = 0;
        for (int right = 0; right < s.length(); right++) {
            window[s[right]]++;
            if (right - left + 1 > p.length()) {
                window[s[left]]--;
                if (window[s[left]] == 0) {
                    window.erase(s[left]);
                };
                left++;
            }
            if (right - left + 1 == p.length() && window == freq) {
                ans.push_back(left);
            }
        }

        return ans;
    }
};