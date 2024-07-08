class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int medianIdx;
        if (n % 2 == 0) medianIdx = n / 2;
        else medianIdx = (n + 1) / 2 - 1;
        
        long long numOps = abs(k - nums[medianIdx]);
        if (k > nums[medianIdx]) { // search to right
            int idx = medianIdx + 1;
            while (idx < n) {
                if (k > nums[idx]) numOps += abs(k - nums[idx]);
                else break;
                idx += 1;
            }
        } else if (k < nums[medianIdx]) { // search to left
            int idx = medianIdx - 1;
            while (idx >= 0) {
                if (k < nums[idx]) numOps += abs(k - nums[idx]);
                else break;
                idx -= 1;
            }
        }
        return numOps;
    }
};