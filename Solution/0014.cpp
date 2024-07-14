class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = "";

        int minStringLen = INT_MAX;
        for (string str : strs) minStringLen = min(minStringLen, (int)str.length());

        for (int i = 0; i < minStringLen; ++i) {
            bool isPrefix = true;
            for (int j = 0; j < strs.size() - 1; ++j) {
                if (strs[j][i] != strs[j + 1][i]) {
                    isPrefix = false;
                    break;
                }
            }
            if (isPrefix) prefix += strs[0][i];
            else break;
        }
        return prefix;
    }
};