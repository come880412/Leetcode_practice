class Solution {
public:
    bool detectVowel(char c) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
        else return false;
    }

    bool doesAliceWin(string s) {
        for (char c : s) {
            if (detectVowel(c)) return true;
        }
        return false;
    }
};