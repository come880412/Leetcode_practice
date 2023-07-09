// Greedy Algorithm
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int end_idx = nums.size() - 1;
        int maxPosition = 0;
    
        for (int curr_idx=0; curr_idx<nums.size(); ++curr_idx) {
           int curr_jump = nums[curr_idx];
           if (curr_idx > maxPosition || maxPosition >= end_idx)
               break;
           maxPosition = max(curr_idx + curr_jump, maxPosition);
        }
        
        return maxPosition >= end_idx;
    }
};

// Dynamic Programming

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums[0] == 0 && nums.size() != 1) return false;
        else if(nums.size() == 1) return true;
        vector<int> restStep={nums[0]};
        
        for (int i=1; i<nums.size()-1; ++i) {
            restStep.push_back(max(nums[i], restStep[i-1] - 1));
            if (restStep[i] == 0)
                return false;
        }
        return true;
    }
};