class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        const int n = items.size(), m = queries.size();
        sort(items.begin(), items.end());

        vector<int> ans(m, 0);
        vector<int> store(n, 0);

        store[0] = items[0][1];
        for (int i = 1; i < n; ++i) 
            store[i] = max(store[i-1], items[i][1]);

        for (int i = 0; i < m; ++i) {
            int query = queries[i];
            int idx = binarySearch(items, query);
            if (idx != -1) ans[i] = store[idx];
        }
        return ans;
    }

    int binarySearch(const vector<vector<int>>& items, int query) {
        int left = 0, right = items.size() - 1;
        int result = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (items[mid][0] <= query) {
                result = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return result;
    }
};