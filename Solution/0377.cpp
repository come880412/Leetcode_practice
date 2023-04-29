class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<uint> dp;
        for(int i=0; i<target; ++i)
            dp.push_back(0);
        
        for(int t=1; t<=target; ++t){
            for(int i=0; i<nums.size(); ++i){
                int num = nums[i];
                if(num == t)
                    dp[t-1] = dp[t-1] + 1;
                else if(num < t)
                    dp[t-1] = dp[t-1] + dp[t-num-1];
            }
        }
        return dp[target-1];
    }
};