class Solution {
    public:
        bool containsDuplicate(vector<int>& nums) {
            unordered_set<int> seen;
    
            for (int i = 0; i < nums.size(); ++i) {
                if (seen.find(nums[i]) != seen.end())
                    return true;
                
                seen.insert(nums[i]);
            }
    
            return false;
        }
};