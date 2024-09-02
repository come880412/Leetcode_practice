class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        const int n = chalk.size();
        vector<long long> accSum;
        accSum.emplace_back(chalk[0]);
        for (int i = 1; i < n; ++i) {
            accSum.emplace_back(accSum[i - 1] + chalk[i]);
        }

        k %= accSum[n - 1];
        int l = 0, r = n - 1;
        while (l != r) {
            int m = l + (r - l) / 2;
            if (k > accSum[m]) l = m + 1;
            else if (k < accSum[m]) r = m;
            else {
                if (m + 1 > n - 1) return 0;
                else return m + 1;
            }
        }
        return r;
    }
};