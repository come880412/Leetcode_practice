class Solution {
public:
    void findSubstring(string s, unordered_map<string, int>& m) {
        size_t pos = 0;
        string subString;
        while (true) {
            size_t stringLen = s.find(" ", pos);
            if (stringLen != std::string::npos) {
                subString = s.substr(pos, stringLen - pos);
                pos = stringLen + 1;
                m[subString] += 1;
            } 
            else {
                subString = s.substr(pos, s.length() - pos);
                m[subString] += 1;
                break;
            }
        }
    }

    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> m;

        findSubstring(s1, m);
        findSubstring(s2, m);
        vector<string> result;
        for (const auto& [key, value] : m) {
            if (value == 1) result.push_back(key);
        }

        return result;
    }
};