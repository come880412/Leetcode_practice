class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();
        if (n == 1) return true;
        else {
            for (int i = 0; i < n / 2; ++i) {
                if (s[i] != s[n - 1 - i])
                    return false;
            }
            return true;
        }
    }

    void findSubstring(const string s, std::vector<string> &tmp, std::vector<std::vector<string>> &result) {
        int n = s.length();
        if (n == 0) result.push_back(tmp);

        for (int i = 0; i < n; ++i) {
            string subString = s.substr(0, i + 1);
            if (isPalindrome(subString)) {
                tmp.push_back(subString);
                findSubstring(s.substr(i + 1), tmp, result);
                tmp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        int n = s.length();

        std::vector<std::vector<string>> result;
        std::vector<string> tmp;
        findSubstring(s, tmp, result);

        return result;
    }
};