class Solution {
public:
    void helper(const vector<int>& nums, int& ans, int currIdx, int bitwiseOr) {
        if (bitwiseOr == maxNum_) ans++;

        for (int i = currIdx; i < nums.size(); ++i) {
            helper(nums, ans, i + 1, bitwiseOr | nums[i]);
        }
    }

    int countMaxOrSubsets(vector<int>& nums) {
        const int n = nums.size();
        for (int num : nums) maxNum_ |= num;

        int ans = 0;
        helper(nums, ans, 0, 0);

        return ans;
    }
private:
    int maxNum_ = 0;

};