class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_map<char, int> m;
        for (char c : allowed) m[c] = 1;

        int result = 0;
        for (const string word : words) {
            bool isConsistent = true;
            for (const char w : word) {
                if (m.find(w) == m.end()) {
                    isConsistent = false;
                    break;
                }
            }
            if (isConsistent) result += 1;
        }
        return result;
    }
};