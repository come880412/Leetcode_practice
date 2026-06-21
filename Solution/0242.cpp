class Solution {
    public:
        bool isAnagram(string s, string t) {
            int s_length = s.length(), t_length = t.length();
            if (s_length != t_length) return false;
            unordered_map<char, int> count;
    
            for (int i = 0; i < s_length; ++i) {
                auto it = count.find(s[i]);
                if (it == count.end()) 
                    ++count[s[i]];
            }
    
            for (int i = 0; i < t_length; ++i) {
                auto it = count.find(t[i]);
                if (it == count.end()) 
                    return false;
                else {
                    if (--it->second == 0) count.erase(t[i]);
                }
            }
            return count.empty();
        }
    };