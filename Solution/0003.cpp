class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();

        unordered_map<char, int> map;
        int prev = -1;
        int result = 0;
        for (int i = 0; i < n; ++i) {
            if (map.find(s[i]) != map.end() && map[s[i]] > prev) {
                prev = map[s[i]];
            }
            map[s[i]] = i;
            result = max(result, i - prev);
        }
        return result;
    }
};