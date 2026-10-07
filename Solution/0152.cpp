class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int result = nums[0], minProduct = nums[0], maxProduct = nums[0];

        for (int i = 1; i < nums.size(); ++i) {
            int num = nums[i];
            int newMax = max({num, maxProduct*num, minProduct*num});
            int newMin = min({num, maxProduct*num, minProduct*num});
            maxProduct = newMax;
            minProduct = newMin;
            result = max(result, maxProduct);
        }
        return result;
    }
};