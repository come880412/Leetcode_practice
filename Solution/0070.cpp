class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp;
        
        for(int i=0; i<=n; ++i)
            dp.push_back(1);
        
        for(int i=2; i<=n; ++i)
            dp[i] = dp[i-1] + dp[i-2];
        
        return dp[n];
    }
};