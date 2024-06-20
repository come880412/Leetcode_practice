class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;

        for (int x : nums) pq.push(x);
        
        int result;
        for (int i = 0; i < k; ++i) {
            result = pq.top();
            pq.pop();
        }
        return result;
    }
};