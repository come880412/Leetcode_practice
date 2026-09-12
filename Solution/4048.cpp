class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int, vector<int>> m;
        vector<int> cnt(101, 0);

        for (int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            cnt[num]++;
            m[num].push_back(i);
        }

        int out = 0;
        for (int i = 1; i < cnt.size(); ++i) {
            if (cnt[i] == 3 && m[i][1] - m[i][0] == m[i][2] - m[i][1])
                out++;
        }
        return out;
    }
};