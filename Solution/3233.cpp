class Solution {
public:
    bool isPrime(const int num) {
        int i = 2;
        while (i * i <= num) {
            if (num % i == 0) return false;
            i++;
        }
        return true;
    }

    int nonSpecialCount(int l, int r) {
        int p = 2, specialCnt = 0, result = 0;
        while (p * p <= r) {
            if (p * p >= l && isPrime(p)) specialCnt++;
            p++;
        }
        int totalCnt = r - l + 1;
        return totalCnt - specialCnt;
    }
};