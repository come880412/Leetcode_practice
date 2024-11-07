class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        unordered_map<int, int> m;
        for (int i = 0; i < 32; ++i) {
            for (const int num : candidates) {
                if (((num >> i) & 1) == 1) m[i]++;
            }
        }

        int ans = 0;
        for (const auto [key, value] : m) {
            ans = max(ans ,value);
        }
        return ans;
    }
};