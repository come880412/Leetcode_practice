class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        const int n = words.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n; ++j) {
                if (isPrefixAndSuffix(words[i], words[j])) ans++;
            }
        }
        return ans;
    }

    bool isPrefixAndSuffix(string str1, string str2) {
        const int n1 = str1.length();
        const int n2 = str2.length();
        if (n1 > n2) return false;
        else {
            for (int i = 0; i < n1; ++i) {
                if (str1[i] != str2[i]) return false;      // prefix
                if (str1[i] != str2[n2-n1+i]) return false; // suffix
            }
        }
        return true;
    }
};