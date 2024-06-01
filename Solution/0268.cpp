class Solution {
public:
    int missingNumber(vector<int>& nums) {
        std::vector<bool> hitMap(nums.size(), false);
        
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] >= nums.size()) continue;
            else {
                hitMap[nums[i]] = true;
            }
        }

        int result;
        for (int i = 0; i < hitMap.size(); ++i) {
            if (!hitMap[i]) {
                result = i;
                break;
            }
        }
        return result;
    }
};