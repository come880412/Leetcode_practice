class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        const int n = s1.length();

        int num_mistake = 0;
        int prev_idx = 0;
        for (int i = 0; i < n; ++i) {
            if (s1[i] != s2[i]) {
                num_mistake++;
                if (num_mistake == 2) {
                    if (s1[prev_idx] != s2[i] || s1[i] != s2[prev_idx]) return false;
                }
                else if (num_mistake > 2) break;
                prev_idx = i;
            }
        }
        return (num_mistake == 0 || num_mistake == 2) ? true : false;
    }
};