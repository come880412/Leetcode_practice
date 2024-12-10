class Solution {
public:
    int maximumLength(string s) {
        unordered_map<string, int> m;
        int maxLen = -1;
        int l = 1, r = s.size() - 2;

        while (l <= r) {
            int win_size = l + (r - l) / 2;
            bool achieve = false;
            for (int i = 0; i <= s.size() - win_size; ++i) {
                string subStr = s.substr(i, win_size);
                if (m.find(subStr) == m.end()) m[subStr] = 0;
                m[subStr]++;
                if (m[subStr] == 3 && isSpecial(subStr)) {
                    achieve = true;
                    break;
                }
            }
            if (achieve) {
                maxLen = max(maxLen, win_size);
                l = win_size + 1;
            } else {
                r = win_size - 1;
            }
        }
        return maxLen;
    }

    bool isSpecial(string s) {
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] != s[i-1]) return false;
        }
        return true;
    }
};