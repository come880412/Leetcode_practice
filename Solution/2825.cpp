class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        if (m > n) return false;

        int idx = 0;
        for (int i = 0; i < n; ++i) {
            char nextChar = (str1[i] == 'z') ? 'a' : char(str1[i] + 1);
            if (str1[i] == str2[idx] || nextChar == str2[idx]) 
                idx++;
            if (idx == m) break;
        }
        return idx == m;
    }
};