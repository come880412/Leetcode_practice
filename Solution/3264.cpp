class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        const int n = nums.size();
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        for (int i = 0; i < n; ++i) pq.push({nums[i], i});

        for (int i = 0; i < k; ++i) {
            auto [num, id] = pq.top();
            pq.pop();
            num *= multiplier;
            pq.push({num, id});
        }

        vector<int> ans(n, 0);
        while(!pq.empty()) {
            auto [num, id] = pq.top();
            ans[id] = num;
            pq.pop();
        }
        return ans;
    }
};