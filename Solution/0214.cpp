class Solution {
public:
    string shortestPalindrome(string s) {
        const int n = s.size();
        string FRstring(s + '#' + string(s.rbegin(), s.rend()));

        vector<int> kmpTable(FRstring.size(), 0);
        for (int i = 1; i < FRstring.size(); ++i) {
            int m = kmpTable[i - 1];

            while (m > 0 && FRstring[i] != FRstring[m])
                m = kmpTable[m - 1];

            if (FRstring[i] == FRstring[m]) ++m;
            kmpTable[i] = m;
        }
        string addString(string(s.rbegin(), s.rend()).substr(0, n - kmpTable.back()));
        return addString + s;
    }
}; 