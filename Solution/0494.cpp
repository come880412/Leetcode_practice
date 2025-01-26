class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        const int n = nums.size();
        helper(nums, n, target, 0, 0);

        return ans_;
    }

    void helper(const vector<int>& nums, const int n, const int target, int idx, int currSum) {
        if (idx >= n) {
            if (target == currSum) ans_++;
            return;
        }

        helper(nums, n, target, idx + 1, currSum + nums[idx]);
        helper(nums, n, target, idx + 1, currSum - nums[idx]);
    }

private:
    int ans_ = 0;
};