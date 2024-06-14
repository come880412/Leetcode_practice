class Solution {
public:
    int maxTotalReward(vector<int>& rewardValues) {
        int n = rewardValues.size();
        sort(rewardValues.begin(), rewardValues.end());

        vector<int> dp(4001, 0);
        dp[0] = 1;

        for (int num : rewardValues) {
            for (int j = 0; j < num; ++j) {
                if (dp[j]) dp[j + num] = 1;
            }
        }
        
        for (int i = dp.size()-1; i >= 0; --i) {
            if (dp[i]) return i;
        }

        return 0;
    }
};