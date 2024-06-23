class Solution {
public:
    long long maximumTotalCost(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        
        vector<long long> dp;
        dp.push_back((long long)nums[0]);
        
        for (int i = 1; i < n; ++i) {
            long long selfSplit = (long long)nums[i] + dp[i - 1];
            long long withOldGroup = (i >= 2) ? nums[i - 1] - nums[i] + dp[i - 2] : nums[i - 1] - nums[i] + 0;
            dp.push_back(max(selfSplit, withOldGroup));
        }
        return dp[n - 1];
    }
};