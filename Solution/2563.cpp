class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        long long ans = 0;

        int i = 0, j = nums.size() - 1;
        for (int i = 0; i < nums.size(); ++i){
            int left = findLower(nums, lower - nums[i], i + 1);
            int right = findUpper(nums, upper - nums[i], i + 1);
            
            if (left != -1 && right != -1 && left <= right) {
                ans += (right - left + 1);
            }
        }
        return ans;

    }
    int findLower(const vector<int>& nums, int target, int start) {
        int left = start, right = nums.size() - 1;
        int idx = -1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= target) {
                idx = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        return idx;
    }

    int findUpper(const vector<int>& nums, int target, int start) {
        int left = start, right = nums.size() - 1;
        int idx = -1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > target) {
                right = mid - 1;
            } else {
                idx = mid;
                left = mid + 1;
            }
        }
        
        return idx;
    }
};