class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        const int n = words.size();
        const int m = queries.size();
        vector<int> prefix(n+1, 0);
        
        for (int i = 0; i < n; ++i) {
            string word = words[i];
            char startW = word[0], endW = word[word.length()-1];
            if (isVowel(startW) && isVowel(endW))
                prefix[i+1] = prefix[i] + 1;
            else
                prefix[i+1] = prefix[i];
        }

        vector<int> ans(m, 0);
        for (int i = 0; i < m; ++i) {
            int s = queries[i][0], e = queries[i][1];
            ans[i] = prefix[e+1] - prefix[s];
        }
        return ans;
    }

    bool isVowel(char c) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            return true;
        else 
            return false;
    }
};