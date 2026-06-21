class Solution {
    public:
    
        bool isValid(string s) {
            stack<char> storage;
    
            unordered_map<char, char> pair = {
                {')', '('},
                {'}', '{'},
                {']', '['}
            };
    
            for(int i = 0; i < s.length(); ++i) {
                char c = s[i];
                auto it = pair.find(c);
    
                if (it == pair.end()) {
                    storage.push(c);
                } else{
                    if (storage.empty() || storage.top() != it->second)
                        return false;
                    storage.pop();
                }
            }
            return storage.empty();
        }
};