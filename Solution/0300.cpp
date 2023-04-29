// O(n^2) solution
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp;
        for(int i=0; i<nums.size(); ++i)
            dp.push_back(1);
        int out=1;
        for(int i=0; i<nums.size(); ++i){
            for(int j=0; j<i; ++j){
                if(nums[i] > nums[j]){
                    dp[i] = max(dp[i], dp[j] + 1);
                    if(dp[i] > out)
                        out = dp[i];
                }
            }
        }
        return out;
    }
};