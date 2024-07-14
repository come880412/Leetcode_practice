class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s = 0;
        int e = nums.size() - 1;
        
        while (s <= e) {
            int m = (s + e) / 2;
            
            if (nums[m] == target) return m;

            if (nums[m] >= nums[s]) { // left half is sorted array
                if (nums[m] > target && target >= nums[s]) e = m - 1;
                else s = m + 1;
            } else { // right half is sorted array
                if (nums[m] < target && target <= nums[e]) s = m + 1;
                else e = m - 1;
            }
        }
        return -1;
    }
};