class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> p(n+1, 0);
        for (int i = 1; i <= n; ++i) p[i] = p[i-1] + nums[i-1];

        deque<int> dq;
        int ans = n + 1;
        for (int r = 0; r <= n; ++r) {
            while (!dq.empty() && p[r] - p[dq.front()] >= k) {
                ans = min(ans, r - dq.front());
                dq.pop_front();
            }

            while (!dq.empty() && p[dq.back()] >= p[r]) {
                dq.pop_back();
            }
            dq.push_back(r);
        }
        return ans == n + 1 ? -1 : ans;
    }
};