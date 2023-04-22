class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp;
        dp.push_back(0);
        for(int i=1; i<=amount; ++i)
            dp.push_back(-1);
        
        for(int i=0; i<coins.size(); ++i){
            int coin = coins[i];
            for(int a=1; a<=amount; ++a){
                if(a >= coin && dp[a-coin] != -1){
                    if(dp[a] != -1)
                        dp[a] = min(dp[a-coin] + 1, dp[a]);
                    else
                        dp[a] = dp[a-coin] + 1;
                }
            }
        }
        return dp[amount];
    }
};