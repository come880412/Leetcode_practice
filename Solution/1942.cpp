class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int targetArrival = times[targetFriend][0];
        sort(times.begin(), times.end());

        priority_queue<int, vector<int>, greater<int>> pq_chair;
        for (int i = 0; i < targetArrival; ++i) pq_chair.push(i);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq_leaving;
        for (int i = 0; i < times.size(); ++i) {
            int arrival = times[i][0], leaving = times[i][1];

            while (!pq_leaving.empty() && pq_leaving.top().first <= arrival) {
                pq_chair.push(pq_leaving.top().second);
                pq_leaving.pop();
            }
            int pos = pq_chair.top();
            pq_chair.pop();

            if (arrival == targetArrival) return pos;

            pq_leaving.push({leaving, pos});
        }
        return 0;
    }
};