class Solution {
public:
    int minSteps(int n) {
        int result = 0;
        int factor = 2;
        while (n > 1) {
            while (n % factor == 0) {
                result += factor;
                n /= factor;
            }
            factor++;
        }

        return result;
    }
};