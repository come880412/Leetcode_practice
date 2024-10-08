class Solution {
public:
    int minSwaps(string s) {
        int extraClosingBracket = 0;
        int maxExtra = 0;

        // Calculate how many extra closing bracket they are.
        for (char c : s) {
            if (c == ']') extraClosingBracket += 1;
            else extraClosingBracket -= 1;
            
            maxExtra = max(maxExtra, extraClosingBracket);
        }

        // Since swapping once can reduce two extra closing bracket.
        // e.g, s = "]]][[[" --> maxExtra = 3
        // ---- After 1 swap ----
        // s = "[]][][" --> maxExtra = 1
        // ---- After 2 swap ----
        // s = "[]" --> maxExtra = 0
        return (maxExtra + 1) / 2;
    }
};