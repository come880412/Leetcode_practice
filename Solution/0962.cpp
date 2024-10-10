class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        stack<int> monoDecStack;

        for (int i = 0; i < nums.size(); ++i) {
            if (monoDecStack.empty() || nums[monoDecStack.top()] > nums[i])
                monoDecStack.push(i);
        }

        int maxWidth = 0;
        for (int i = nums.size() - 1; i > 0; --i) {
            while (!monoDecStack.empty() && nums[monoDecStack.top()] <= nums[i]) {
                maxWidth = max(maxWidth, i - monoDecStack.top());
                monoDecStack.pop();
            }
        }
        return maxWidth;
    }
};