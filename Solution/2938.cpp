class Solution {
public:
    long long minimumSteps(string s) {
        int n = s.size();
        
        long long ans = 0;
        int oneIdx = -1;
        int i = 0;
        while (i < n) {
            if (s[i] == '1' && oneIdx == -1) {
                oneIdx = i;
            } else if (s[i] == '0' && oneIdx != -1) {
                ans += (i - oneIdx);
                s[oneIdx] = '0';
                s[i] = '1';
                oneIdx++;
            }
            i++;
        }
        return ans;
    }
};