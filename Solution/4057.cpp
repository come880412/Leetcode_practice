class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[0] < b[0];
             });

        priority_queue<int, vector<int>, greater<int>> p;

        long long ans = 0;
        for (const auto& iv : intervals) {
            int start = iv[0], end = iv[1];

            while (!p.empty() && p.top() < start) 
                p.pop();

            ans += (long long)p.size();
                    
            p.push(end);
        }
        return ans;
    }
};