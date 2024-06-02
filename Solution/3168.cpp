class Solution {
public:
    int minimumChairs(string s) {
        int sum = 0;
        int result = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == 'E') {
                sum += 1;
                if (sum > result)
                    result = sum;
            }
            else if (s[i] == 'L') {
                sum -= 1;
            }
        }
        
        return result;
    }
};