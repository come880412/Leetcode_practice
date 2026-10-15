class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> maxHeap;
        for (int pile : piles) maxHeap.push(pile);

        for (int i = 0; i < k; ++i) {
            int top = maxHeap.top();
            top -= (top / 2);
            maxHeap.pop();
            maxHeap.push(top);
        }

        int result = 0;
        while (!maxHeap.empty()) {
            result += maxHeap.top();
            maxHeap.pop();
        }
        return result;
    }
};