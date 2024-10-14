class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for (int num : nums) pq.push(num);

        long long ans = 0;
        for (int i = 0; i < k; ++i) {
            int val = pq.top();
            pq.pop();
            ans += val;
            val = (val + 2) / 3;
            pq.push(val);
        }
        return ans;
    }
};