class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s = 0;
        int e = nums.size() - 1;
        
        while (s <= e) {
            int m = (s + e) / 2;
            
            if (nums[m] == target) return m;
            else if (nums[m] > target) {
                if (target < nums[s] && nums[m] >= nums[s]) s = m + 1;
                else e = m - 1;
            } else {
                if (target > nums[e] && nums[m] < nums[s]) e = m - 1;
                else s = m + 1;
            }
        }
        return -1;
    }
};