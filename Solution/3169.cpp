#include <algorithm>

class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        
        int prevEnd = meetings[0][1];
        int result = meetings[0][0] - 1;

        for (int i = 1; i < meetings.size(); ++i) {
            int start = meetings[i][0], end = meetings[i][1];
            if (start > prevEnd) result += (start - prevEnd - 1);

            prevEnd = std::max(prevEnd, end);
        }
        result += (days - prevEnd);
        
        return result;
    }
};