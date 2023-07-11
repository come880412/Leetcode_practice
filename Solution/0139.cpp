class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // To achieve O(1) searching time.
        unordered_set <string> wordHashSet(wordDict.begin(), wordDict.end());
        vector <bool> record(s.length() + 1, false);
        
        record[0] = true;
        for (int i=0; i<s.length(); ++i) {
            for (int j=0; j<=i; ++j) {
                string subStr = s.substr(j, i-j+1);
                if(record[j] && wordHashSet.count(subStr)) {
                    record[i+1] = true;
                    break;
                }
            }
        }
        
        return record[s.length()];
    }
};