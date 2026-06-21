class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            unordered_map<int, int> indexMap;
            indexMap.reserve(nums.size());
    
            for (int i = 0; i < nums.size(); ++i) {
                int complement = target - nums[i];
                auto it = indexMap.find(complement);
                if (it != indexMap.end())
                    return {i, it->second};
    
                indexMap[nums[i]] = i;
            }
            return {};
        }
};