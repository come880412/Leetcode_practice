class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int singleSum = 0, doubleSum = 0;

        for (const int num : nums) {
            if (num / 10 == 0) singleSum += num;
            else doubleSum += num;
        }

        if (singleSum > doubleSum || singleSum < doubleSum) return true;
        else return false;
    }
};