class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        const int n = prices.size();
        vector<int> ans(n, 0);

        for (int i = 0; i < n; ++i) {
            int price = prices[i];
            int idx = i + 1;
            while (idx < n) {
                if (prices[idx] <= price) break;
                idx++;
            }
            int discount = (idx < n) ? prices[idx] : 0;
            ans[i] = price - discount;
        }
        return ans;
    }
};