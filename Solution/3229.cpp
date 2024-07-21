class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        int n = nums.size();
        long long inc = 0, dec = 0, result = 0;

        for (int i = 0; i < n; ++i) {
            long long diff = target[i] - nums[i];

            if (diff > 0) {
                if (inc < diff) result += diff - inc;
                inc = diff;
                dec = 0;
            } else if (diff < 0) {
                if (abs(dec) < abs(diff)) result += abs(diff) - abs(dec);
                inc = 0;
                dec = diff;
            } else {
                inc = 0;
                dec = 0;
            }
        }
        return result;
    }
};