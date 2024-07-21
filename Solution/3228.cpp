class Solution {
public:
    int maxOperations(string s) {
        int n = s.length();
        int oneCnt = 0;
        bool isZero = false;
        int result = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                if (isZero) {
                    result += oneCnt;
                    isZero = false;
                }
                oneCnt++;
            } else if (s[i] == '0') {
                isZero = true;
            }
        }
        if (isZero) result += oneCnt;
        return result;
    }
};