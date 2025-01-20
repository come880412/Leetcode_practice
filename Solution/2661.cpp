class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        const int m = mat.size(), n = mat[0].size();
        unordered_map<int, pair<int, int>> pos;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                pos[mat[i][j]] = make_pair(i, j);
            }
        }

        vector<int> record(m+n, 0);
        for (int i = 0; i < arr.size(); ++i) {
            auto [x, y] = pos[arr[i]];
            record[x]++;
            record[y+m]++;
            if (record[x] == n || record[y+m] == m) return i;
        }
        return -1;
    }
};