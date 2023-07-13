/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param intervals: an array of meeting time intervals
     * @return: the minimum number of conference rooms required
     */
    // Time complexity: O(n log n)
    // Space complexity: O(n)
    int minMeetingRooms(vector<Interval> &intervals) {
        // Write your code here.
        sort(intervals.begin(), intervals.end(), [](Interval a, Interval b){
            return a.start < b.start; 
        }); // O(n log n)
        priority_queue <int, vector<int>, greater<int> > rooms;
        rooms.push(intervals[0].end);
        // O(n log n)
        for (int i=1; i<intervals.size(); ++i) { 
            if (intervals[i].start >= rooms.top())
                rooms.pop(); // O(log n)
            rooms.push(intervals[i].end); // O(log n)
        }
        
        return rooms.size();
    }
};