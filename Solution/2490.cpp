class Solution {
public:
    bool isCircularSentence(string sentence) {
        vector<string> s;
        size_t start = 0;
        size_t pos = sentence.find(' ', start);
        while(pos != string::npos) {
            s.emplace_back(sentence.substr(start, pos - start));
            start = pos + 1;
            pos = sentence.find(' ', start);
            if (pos == string::npos) s.emplace_back(sentence.substr(start, pos));
        }

        const int n = s.size();
        if (n == 0 && sentence.front() != sentence.back()) return false;
        for (int i = 0; i < n - 1; ++i) {
            if (i == 0 && s[i].front() != s[n-1].back()) return false;
            if (s[i].back() != s[i+1].front()) return false;
        }

        return true;
    }
};