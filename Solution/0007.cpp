class Solution {
public:
    int reverse(int x) {
        int result = 0;
        int cnt = 0;
        while (x != 0) {
            int num = x % 10;
            x /= 10;
            if (result > INT_MAX / 10) return 0;
            if (result < INT_MIN / 10) return 0;
            result = (result * 10) + num;
        }

        return result;
    }
};