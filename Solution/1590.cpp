class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int remainder = 0;
        for (int num : nums) remainder = (remainder + num) % p;

        if (remainder == 0) return 0;
        
        int ans = nums.size();
        unordered_map<int, int> m;
        m[0] = -1;
        int prefixMod = 0;
        for (int i = 0; i < nums.size(); ++i) {
            prefixMod = (nums[i] + prefixMod) % p;
            int targetMod = (prefixMod - remainder + p) % p;

            if (m.find(targetMod) != m.end())
                ans = min(ans, i - m[targetMod]);
            
            m[prefixMod] = i;
        }
        return ans == nums.size() ? -1 : ans;
    }
};