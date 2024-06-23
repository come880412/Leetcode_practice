class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        double minAvg = DBL_MAX;
        for (int i = 0; i < n / 2; ++i) minAvg = min(minAvg, ((double)nums[i] + nums[n - i - 1]) / 2);

        // priority_queue<int> pq_max;
        // priority_queue<int, vector<int>, greater<int>> pq_min;
        
        // for (int x : nums) {
        //     pq_max.push(x);
        //     pq_min.push(x);
        // }
        
        // double minAvg = DBL_MAX;
        // while (pq_max.size() > n / 2) {
        //     double avg = (pq_max.top() + (double)pq_min.top()) / 2;
        //     pq_max.pop();
        //     pq_min.pop();
        //     if (avg < minAvg) minAvg = avg; 
        // }
        
        return minAvg;
    }
};