class Solution {
public:
    int minLength(string s) {
        int n = s.size();
        int i = 0;
        while (i < n) {
            if ((n - i) >= 2 && (s.substr(i, 2) == "AB" || s.substr(i, 2) == "CD")) {
                s.erase(i, 2);
                n = s.size();
                i = -1;
            }
            i++;
        }
        return n;
    }
};