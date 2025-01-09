class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int ans = 0;
        for (int i = 0; i < words.size(); ++i) {
            if (words[i].length() >= pref.length() && words[i].substr(0, pref.length()) == pref)
                ans++;
        }
        return ans;
    }
};