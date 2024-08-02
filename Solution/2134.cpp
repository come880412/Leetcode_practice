class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        int windowSize = count(nums.begin(), nums.end(), 1); // Maximum swap times

        int numSwaps = count(nums.begin(), nums.begin() + windowSize, 0);
        int result = numSwaps;
        for (int startIdx = 1; startIdx < n; ++startIdx) {
            int endIdx = (startIdx + windowSize - 1) % n; // Due to circular array
            if (nums[startIdx - 1] == 0 && nums[endIdx] == 1) numSwaps--;
            else if (nums[startIdx - 1] == 1 && nums[endIdx] == 0) numSwaps++;
            result = min(result, numSwaps);
        }
        return result;
    }
};