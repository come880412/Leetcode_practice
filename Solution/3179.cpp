class Solution {
public:
    int valueAfterKSeconds(int n, int k) {
        vector <int> result(n, 1);
        int moduloNum = pow(10, 9) + 7;
        
        for (int i = 1; i <= k; ++i) {
            for (int j = 1; j < n; ++j) {
                result[j] += result[j - 1];
                result[j] = result[j] % moduloNum;
            }
        }
        return result[n - 1];
    }
};