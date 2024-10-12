class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        const int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int>> pq;

        int groupCnt = 0;
        for (int i = 0; i < n; ++i) {
            int start = intervals[i][0], end = intervals[i][1];
            pq.push(end);
            if (start <= pq.top()) groupCnt++;
            else pq.pop();
        }
        return groupCnt;
    }
};