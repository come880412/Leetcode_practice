class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long pos = 0, neg = 0;
        for (int num : nums) {
            long long newPos = max(pos, neg+num);
            long long newNeg = max(neg, pos-num);
            pos = newPos;
            neg = newNeg;
        }
        return pos;
    }
};