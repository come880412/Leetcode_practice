class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        const int n = nums.size();
        map<int, int, greater<int>> record;
        vector<int> ans;

        for (int i = 0; i < n - k + 1; ++i) {
            priority_queue<pair<int, int>> pq;
            int cntx = 0;
            if (i == 0) {
                for (int j = 0; j < k; ++j)
                    record[nums[j]]++;
            } else {
                record[nums[i-1]]--;
                record[nums[i+k-1]]++;
            }
            for (const auto& [key, value] : record)
                pq.push({value, key});

            int xSum = 0;
            for (int j = 0; j < x; ++j) {
                xSum += pq.top().first * pq.top().second;
                pq.pop();
                if (pq.empty()) break;
            }
            ans.emplace_back(xSum);
        }
        return ans;
    }
};