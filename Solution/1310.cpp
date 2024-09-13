class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> prefixSum = {arr[0]};
        for (int i = 1; i < arr.size(); ++i) prefixSum.push_back(prefixSum.back() ^ arr[i]);

        vector<int> result;
        for (const auto& query : queries) {
            int left = query[0], right = query[1];
            if (left == 0) result.push_back(prefixSum[right]);
            else result.push_back(prefixSum[right] ^ prefixSum[left - 1]);
        }

        return result;
    }
};