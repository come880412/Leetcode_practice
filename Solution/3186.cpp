class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        int n = power.size();
        
        map<int, int> countDmg;
        for (int i = 0; i < n; ++i) countDmg[power[i]] += 1;
        
        long long int maxDmg = 0;
        unordered_map<int, long long int> dp;
        vector<int> runningKey;
        int trackingIdx = 0;
        for (const auto &dmg : countDmg) {
            int currDmg = dmg.first;
            int currCount = dmg.second;
            long long int currTotalDmg = currDmg * (long long int) currCount;
            
            long long int maxVal = 0;
            for (int i = trackingIdx; i < runningKey.size(); ++i) {
                if (runningKey[i] < currDmg - 2 && dp[runningKey[i]] > maxVal) {
                    trackingIdx = i;
                    maxVal = dp[runningKey[i]];
                }
            }
            dp[currDmg] = maxVal + currTotalDmg;
            maxDmg = max(maxDmg, dp[currDmg]);
            runningKey.push_back(currDmg);
        }
        return maxDmg;
    }
};