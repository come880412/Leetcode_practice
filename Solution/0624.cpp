class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        const int n = arrays.size();
        int smallest = arrays[0][0];
        int largest = arrays[0].back();

        int maxDist = 0;
        for (int i = 1; i < n; ++i) {
            maxDist = max(maxDist, abs(arrays[i].back() - smallest));
            maxDist = max(maxDist, abs(arrays[i][0] - largest));

            smallest = min(smallest, arrays[i][0]);
            largest = max(largest, arrays[i].back());
        }
        return maxDist;
    }
};