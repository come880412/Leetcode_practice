class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxNum = nums[0];
        int cnt = 1;

        int result = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (maxNum == nums[i]) cnt++;
            else if (maxNum < nums[i]) {
                result = cnt = 1;
                maxNum = nums[i];
            } else cnt = 0;
            result = max(result, cnt);
        }
        return result;
    }
};