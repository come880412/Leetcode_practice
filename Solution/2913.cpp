class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        vector<int> d(n, 0);
        unordered_map<int, int> last;
        int ans = 0;

        int p;
        for (int j = 0; j < n; ++j) {
            if (last.count(nums[j])) p = last[nums[j]];
            else p = -1;
            for (int i = p + 1; i <=j; ++i) d[i]++;
            for (int i = 0; i <= j; ++i) ans += d[i] * d[i];
            last[nums[j]] = j;
        }
        return ans;
    }
};