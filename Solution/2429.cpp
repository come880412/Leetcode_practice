class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int oneBitNum1 = 0;
        int oneBitNum2 = 0;
        for (int i = 0; i < 32; ++i) {
            oneBitNum1 += ((num1 >> i) & 1);
            oneBitNum2 += ((num2 >> i) & 1);
        }

        int ans = num1;
        int cnt = abs(oneBitNum1 - oneBitNum2);
        for (int i = 0; i < 32; ++i) {
            if (cnt == 0)
                break;
            if (oneBitNum1 > oneBitNum2 && (num1 >> i) & 1) {
                ans ^= (1 << i);
                cnt--;
            }
            else if (oneBitNum1 < oneBitNum2 && !((num1 >> i) & 1)) {
                ans |= (1 << i);
                cnt--;
            }
        }
        return ans;
    }
};