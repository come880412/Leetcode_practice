class Solution {
public:
    int minChanges(int n, int k) {
        int result = 0;
        for (int i = 0; i < 20; ++i) {
            if (((n >> i) & 1) ^ ((k >> i) & 1)) {
                if (((n >> i) & 1)) result += 1;
                else return -1;
            }
        }
        return result;
    }
};