class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        int end = intervals[0][1], idx = 0;
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] <= end) {
                end = max(end, intervals[i][1]);
                intervals[idx][1] = end;
            } else {
                ++idx;
                intervals[idx][0] = intervals[i][0];
                intervals[idx][1] = intervals[i][1];
                end = intervals[idx][1];
            }
        }
        intervals.erase(intervals.begin() + idx + 1, intervals.end());
        return intervals;
    }
};