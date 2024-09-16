class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();
        if (n > 1440) return 0;

        vector<int> minutes;
        for (auto const& timePoint : timePoints) {
            int h = stoi(timePoint.substr(0, 2));
            int m = stoi(timePoint.substr(3, 2));
            minutes.push_back(h * 60 + m);
        }
        sort(minutes.begin(), minutes.end());

        int minMin = INT_MAX;
        for (int i = 1; i < n; ++i) {
            minMin = min(minMin, minutes[i] - minutes[i - 1]);
        }

        int cycleDiff = 1440 - (minutes[n - 1] - minutes[0]);
        minMin = min(minMin, cycleDiff);
        return minMin;
    }
};