class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long left = 0, right = 1e18;
        
        while (left < right) {
            long long mid = left + (right - left) / 2;
            if (canReduceHeight(mid, mountainHeight, workerTimes)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
    
private:
    bool canReduceHeight(long long time, int mountainHeight, const vector<int>& workerTimes) {
        long long totalReduction = 0;
        for (int workerTime : workerTimes) {
            long long x = sqrt(2LL * time / workerTime + 0.25) - 0.5;
            totalReduction += x;
            if (totalReduction >= mountainHeight) return true;
        }
        return false;
    }
};