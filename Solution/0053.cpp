class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = nums[0], running_max = nums[0];
        for (int num : nums) {
            running_max = max(running_max+num, num);
            result = max(result, running_max);
        }
        return result;
    }
};