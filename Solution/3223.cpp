class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char, int> m;
        int ans = 0;
        for (int i = 0; i < s.length(); ++i) {
            ans++;
            m[s[i]]++;
            if (m[s[i]] == 3) {
                m[s[i]] -= 2;
                ans -= 2;
            }
        }
        return ans;
    }
};