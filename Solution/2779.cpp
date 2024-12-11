class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int maxLen = 1;
        
        int start = 0;
        for (int i = 1; i < nums.size(); ++i) {
            while (start < i && nums[i] - nums[start] > 2*k) start++;
            maxLen = max(maxLen, i - start + 1);
        }
        return maxLen;
    }
};