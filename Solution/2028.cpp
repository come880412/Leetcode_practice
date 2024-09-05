class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        const int m = rolls.size();
        int sum = 0;
        for (const int roll : rolls) sum += roll;
        
        int remaining = mean * (n + m) - sum;
        int mod = remaining % n;
        int mul = remaining / n;

        vector<int> result(n, mul);
        if (mul <= 0 || mul > 6 || remaining < 0) return {};
        else {
            int idx = 0;
            while (mod != 0 && idx < n) {
                int diff = 6 - mul;
                diff = min(diff, mod);
                result[idx] += diff;
                mod -= diff;
                idx++;
            }
        }

        if (mod == 0) return result;
        else return {};
    }
};