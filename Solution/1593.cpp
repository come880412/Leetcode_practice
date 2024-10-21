class Solution {
public:
    int maxUniqueSplit(string s) {
        return helper(0, s);
    }

    int helper(int startIdx, const string& s) {
        if (startIdx == s.size()) return 0;

        string str;
        int maxSplit = 0;
        for (int i = startIdx; i < s.size(); ++i) {
            str += s[i];
            if (s_.find(str) == s_.end()) {
                s_.insert(str);
                int splitCount = 1 + helper(i + 1, s);
                maxSplit = max(maxSplit, splitCount);
                s_.erase(str);
            }
        }
        return maxSplit;
    }

private:
    unordered_set<string> s_;
};