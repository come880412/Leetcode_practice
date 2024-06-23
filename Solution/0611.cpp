class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        int result = 0;
        for (int i = 2; i < n; ++i) {
            int num = nums[i];
            int left = 0, right = i - 1;

            while (left != right) {
                if (nums[left] + nums[right] > num) {
                    result += right - left;
                    right -= 1;
                } else left += 1;
            }
        }
        return result;
    }
};