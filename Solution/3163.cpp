class Solution {
public:
    string compressedString(string word) {
        const int n = word.size();

        int i = 0;
        string ans;
        while (i < n) {
            char c = word[i];
            int cnt = 0;

            while (i < n && c == word[i] && cnt < 9) {
                cnt++;
                i++;
            }

            ans += (to_string(cnt) + c);
        }
        return ans;
    }
};