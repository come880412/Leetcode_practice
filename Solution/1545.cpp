class Solution {
public:
    string simulation(string S) {
        const int n = S.size();
        string reversedStr = S;
        for (int i = 0; i < (n / 2); ++i) {
            char firstChar = reversedStr[i];
            reversedStr[i] = reversedStr[n-i-1] == '0' ? '1' : '0';
            reversedStr[n-i-1] = firstChar == '0' ? '1' : '0';
        }
        if (n % 2 == 1) {
            int idx = (n-1) / 2;
            reversedStr[idx] = reversedStr[idx] == '0' ? '1' : '0';
        }
        return S + "1" + reversedStr;
    }
    char findKthBit(int n, int k) {
        string S = "0";
        for (int i = 2; i <= n; ++i) S = simulation(S);
        return S[k-1];
    }
};

