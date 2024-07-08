class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();

        int recorder = nums[0];
        int countInc = 1, countDec = 1;
        int maxSubLen = 1;

        for (int i = 1; i < n; ++i) {
            if (nums[i] > recorder) countInc++;
            else countInc = 1;

            if (nums[i] < recorder) countDec++;
            else countDec = 1;
            
            maxSubLen = max({maxSubLen, countInc, countDec});
            recorder = nums[i];
        }
        return maxSubLen;
    }
};