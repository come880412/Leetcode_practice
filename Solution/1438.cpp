class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int l = 0, n = nums.size();
        deque<int> maxQueue;
        deque<int> minQueue;

        int ans = 0;
        for (int r = 0; r < n; ++r) {
            while (!minQueue.empty() && nums[r] < nums[minQueue.back()])
                minQueue.pop_back();
            while (!maxQueue.empty() && nums[r] > nums[maxQueue.back()])
                maxQueue.pop_back();
            minQueue.push_back(r);
            maxQueue.push_back(r);

            while (!minQueue.empty() && !maxQueue.empty() && 
                    nums[maxQueue.front()] - nums[minQueue.front()] > limit) {
                if (minQueue.front() == l) minQueue.pop_front();
                if (maxQueue.front() == l) maxQueue.pop_front();
                ++l;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};