class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int currSum = 0, l = 0;
        
        int ans = n + 1;
        for (int r = 0; r < n; ++r) {
            currSum += nums[r];
            while (currSum >= target) {
                ans = min(ans, r - l + 1);
                currSum -= nums[l];
                ++l;
            }
        }
        return ans == n + 1 ? 0 : ans;
    }
};