class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];
        
        else if(nums.size() == 2)
            return max(nums[0], nums[1]);
            
        else{
            vector<int> dp{nums[0], max(nums[0], nums[1])};
            
            for(int i=2; i<nums.size(); ++i){
                int num = nums[i];
                dp.push_back(max(dp[i-1], dp[i-2] + num));
            }
            return dp[nums.size()-1];
        }
        
    }
};