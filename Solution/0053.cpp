class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> DP;
        
        for(int i=0 ; i<nums.size() ; ++i){
            if(i==0)
                DP.push_back(nums[i]);
            else{
                if(nums[i] + DP[i-1] > nums[i])
                    DP.push_back(nums[i] + DP[i-1]);
                else
                    DP.push_back(nums[i]);
            }
        }
        int maxNum;
        for(int i=0 ; i<DP.size() ; ++i){
            if(i==0)
                maxNum = DP[i];
            else{
                if(DP[i] > maxNum)
                    maxNum = DP[i];
            }
        }
        return maxNum;
        
    }
};
