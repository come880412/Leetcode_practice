class Solution {
public:
    vector<int> minOperations(string boxes) {
        const int n = boxes.length();
        vector<int> ans(n, 0);
        vector<int> leftPrefix(n, 0), rightPrefix(n, 0);
        int cnt = boxes[0] == '1' ? 1 : 0;

        for (int i = 1; i < n; ++i) {
            leftPrefix[i] = leftPrefix[i-1] + cnt;
            cnt += boxes[i] == '1' ? 1 : 0;
        }

        cnt = boxes[n-1] == '1' ? 1 : 0;
        for (int i = n - 2; i >= 0; --i) {
            rightPrefix[i] = rightPrefix[i+1] + cnt;
            cnt += boxes[i] == '1' ? 1 : 0;
        }

        for (int i = 0; i < n; i++) 
            ans[i] = leftPrefix[i] + rightPrefix[i];
        return ans;
    }
};