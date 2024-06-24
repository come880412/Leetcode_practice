class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        
        int totalMul = 1;
        int cnt = 0;
        for (int x : nums) {
            if (x != 0) totalMul *= x;
            else cnt += 1;
        }
        
        for (int i = n - 1; i >= 0; --i) {
            if (cnt >= 2) 
                ans[i] = 0;
            else if (cnt == 1) {
                int val = (nums[i] == 0) ? totalMul : 0;
                ans[i] = val;
            } else 
                ans[i] = totalMul / nums[i];
        }
        return ans;
    }
};