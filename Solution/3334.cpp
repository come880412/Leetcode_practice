class Solution {
public:
    long long maxScore(vector<int>& nums) {
        if (nums.size() == 1) return 1LL * nums[0] * nums[0];
        const int n = nums.size();

        vector<int> prefixGCD(n + 1, 0), suffixGCD(n + 1, 0);
        vector<long long> prefixLCM(n + 1, 1), suffixLCM(n + 1, 1);
        for (int i = 0; i < n; ++i) {
            prefixGCD[i + 1] = gcd(prefixGCD[i], nums[i]);
            prefixLCM[i + 1] = lcm(prefixLCM[i], nums[i]);
        }
            
        for (int i = n - 1; i >= 0; --i) {
            suffixGCD[i] = gcd(suffixGCD[i + 1], nums[i]);
            suffixLCM[i] = lcm(suffixLCM[i + 1], nums[i]);
        }
        
        long long ans = prefixLCM[n] * prefixGCD[n];
        for (int i = 0; i < n; ++i) {
            int currGCD = gcd(prefixGCD[i], suffixGCD[i+1]);
            long long currLCM = lcm(prefixLCM[i], suffixLCM[i+1]);
            ans = max(ans, currLCM * currGCD);
        }
        return ans;
    }
};