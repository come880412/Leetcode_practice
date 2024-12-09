class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        const int n = nums.size();
        const int m = queries.size();
        vector<int> mem(n, 0);

        for (int i = 1; i < n; ++i) {
            if (nums[i-1] % 2 == nums[i] % 2) mem[i] = mem[i-1] + 1;
            else mem[i] = mem[i-1];
        }

        vector<bool> ans(m, true);
        for (int i = 0; i < m; ++i) {
            int from = queries[i][0], to = queries[i][1];
            if (mem[from] != mem[to]) ans[i] = false; 
        }
        return ans;
    }
};