class Solution {
 public :
     bool canAttendMeetings(vector<vector< int >>& intervals) {
        sort(intervals.begin(), intervals.end());
        int start = intervals[0][0], end = intervals[0][1];
        for (int i=1; i<intervals.size(); ++i) {
            if (intervals[i][0] < end) return false;
            start = intervals[0][0];
            end = intervals[0][1];
        }
        return true;
    }
};