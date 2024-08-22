class Solution {
public:
    int findComplement(int num) {
        bool findLeading = false;
        for (int i = 31; i >= 0; --i) {
            if ((num >> i) & 1 || findLeading) {
                num ^= 1 << i;
                findLeading = true;
            }
        }
        return num;
    }
};