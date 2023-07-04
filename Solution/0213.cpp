class Solution {
public:
    int robDP(int s, int e, vector<int> &nums) {
        vector<int> record={nums[s], max(nums[s], nums[s+1])};
        for (int i=s+2; i<e; ++i) {
            int num = nums[i];
            record.push_back(max(num + record[i-2-s], record[i-1-s]));
        }
        
        return record[nums.size()-2];
    }
    
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        else if (nums.size() == 2) return max(nums[0], nums[1]);
            
        return max(robDP(0, nums.size()-1, nums), robDP(1, nums.size(), nums));
    }
};