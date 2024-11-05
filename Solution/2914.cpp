class Solution {
public:
    int minChanges(string s) {
        const int n = s.size();
        int minChange = 0;
        for (int i = 0; i < n - 1; i += 2) {
            if (s[i] != s[i+1]) minChange++;
        }

        return minChange;
    }
};