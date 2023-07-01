class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> output;
        
        
        int newStart = newInterval[0], newEnd = newInterval[1];
        
        int tmpStart=newStart, tmpEnd=newEnd; // Prevent from zero size intervals
        int tmpIdx=0; 
        
        for(int i=0; i<intervals.size(); ++i) {
            int start=intervals[i][0], end=intervals[i][1];
            
            if (end >= newStart) {
                if (start <= newStart) tmpStart = start;
                
                if (start > newEnd) {
                    tmpEnd = newEnd;
                    tmpIdx = i;
                    break;
                }
                else if (start == newEnd) {
                    tmpEnd = end;
                    tmpIdx = i + 1; // Remove current interval
                    break;
                }
                else if (end > newStart && end >=newEnd) {
                    tmpEnd = end;
                    tmpIdx = i + 1; // Remove current interval
                    break;
                }
            }
            else output.push_back(intervals[i]);
            tmpIdx += 1;
            
        }
        // Push the inserted interval
        vector<int> tmpInterval={tmpStart, tmpEnd};
        output.push_back(tmpInterval);
        
        // Push the rest of intervals after insertion
        for(int i=tmpIdx; i<intervals.size(); ++i)
            output.push_back(intervals[i]);
        
        return output;
    }
};