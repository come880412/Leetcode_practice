class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        unordered_map<string, int> bannedMap;
        for (const string& bannedWord : bannedWords) bannedMap[bannedWord] = 1;
        
        int cnt = 0;
        for (const string& msg : message) {
            if (bannedMap.find(msg) != bannedMap.end()) ++cnt;
            
            if (cnt >= 2) return true;
        }
        return false;
    }
};