class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        const int n = nums.size();

        uint16_t currMin = 0, currMax = 0, prevMax = 0;
        uint8_t prevBitCount = 0;
        for (const uint16_t num : nums) {
            const uint8_t bitCount = popcount(num);
            if (bitCount == prevBitCount) {
                currMin = min(currMin, num);
                currMax = max(currMax, num);
            } 
            else if (prevMax > currMin) 
                return false;
            else {
                prevMax = currMax;
                currMin = num;
                currMax = num;
                prevBitCount = bitCount;
            }
        }
        return currMin >= prevMax;
    }
};