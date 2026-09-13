class Solution {
public:
    struct State{
        int count=0;
        int last=0;
        int diff=0;
        int valid=true;
    };

    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int, State> m;

        for (int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            int diff = i - m[num].last;
            if (++m[num].count >= 3 && diff != m[num].diff)
                m[num].valid = false;
            m[num].diff = diff;
            m[num].last = i;
        }

        int out = 0;
        for (auto& item : m) {
            if (item.second.count >= 3 && item.second.valid) out++;
        }
        return out;
    }
};