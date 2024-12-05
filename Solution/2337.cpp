class Solution {
public:
    bool canChange(string start, string target) {
        const int n = start.size();

        int idx = 0;
        for (int i = 0; i < n; ++i) {
            if (target[i] != '_') {
                while (idx < n && start[idx] == '_') 
                    ++idx;
                if (target[i] != start[idx]) return false;
                else if (target[i] == 'R' && idx > i) return false;
                else if (target[i] == 'L' && idx < i) return false;
                idx++;
            }
        }
        for (int i = idx; i < n; ++i) 
            if (start[i] != '_') return false;
        return true;
    }
};